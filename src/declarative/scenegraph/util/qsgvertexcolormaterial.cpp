/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qsgvertexcolormaterial_p.h"

#include <qglshaderprogram.h>

QT_BEGIN_NAMESPACE

class QSGVertexColorMaterialShader : public QSGMaterialShader
{
public:
    virtual void updateState(const RenderState &state, QSGMaterial *newEffect, QSGMaterial *oldEffect);
    virtual char const *const *attributeNames() const;

    static QSGMaterialType type;

private:
    virtual void initialize();
    virtual const char *vertexShader() const;
    virtual const char *fragmentShader() const;

    int m_matrix_id;
    int m_opacity_id;
};

QSGMaterialType QSGVertexColorMaterialShader::type;

void QSGVertexColorMaterialShader::updateState(const RenderState &state, QSGMaterial *newEffect, QSGMaterial *)
{
    if (!(newEffect->flags() & QSGMaterial::Blending) || state.isOpacityDirty())
        program()->setUniformValue(m_opacity_id, state.opacity());

    if (state.isMatrixDirty())
        program()->setUniformValue(m_matrix_id, state.combinedMatrix());
}

char const *const *QSGVertexColorMaterialShader::attributeNames() const
{
    static const char *const attr[] = { "vertexCoord", "vertexColor", 0 };
    return attr;
}

void QSGVertexColorMaterialShader::initialize()
{
    m_matrix_id = program()->uniformLocation("matrix");
    m_opacity_id = program()->uniformLocation("opacity");
}

const char *QSGVertexColorMaterialShader::vertexShader() const {
    return
        "attribute highp vec4 vertexCoord;              \n"
        "attribute highp vec4 vertexColor;              \n"
        "uniform highp mat4 matrix;                     \n"
        "uniform highp float opacity;                   \n"
        "varying lowp vec4 color;                       \n"
        "void main() {                                  \n"
        "    gl_Position = matrix * vertexCoord;        \n"
        "    color = vertexColor * opacity;             \n"
        "}";
}

const char *QSGVertexColorMaterialShader::fragmentShader() const {
    return
        "varying lowp vec4 color;                       \n"
        "void main() {                                  \n"
        "    gl_FragColor = color;                      \n"
        "}";
}



/*!
    \class QSGVertexColorMaterial
    \brief The QSGVertexColorMaterial provides a convenient way of rendering per-vertex
    colored geometry in the scene graph.

    The vertex color material will give each vertex in a geometry a color. Pixels between
    vertices will be linearly interpolated. The colors can contain transparency.

    The geometry to be rendered with vertex color must have the following layout. Attribute
    position 0 must contain vertices. Attribute position 1 must contain colors, a tuple of
    4 values with RGBA layout. Both floats in the range of 0 to 1 and unsigned bytes in
    the range 0 to 255 are valid for the color values. The
    QSGGeometry::defaultAttributes_ColoredPoint2D() constructs an attribute set
    compatible with this material.

    The vertex color material respets both current opacity and current matrix when
    updating it's rendering state.
 */


QSGVertexColorMaterial::QSGVertexColorMaterial()
{
    setFlag(Blending, true);
}



/*!
    Sets if the renderer should treat colors as opaque.

    Setting this flag can in some cases improve performance.
 */

void QSGVertexColorMaterial::setColorsAreOpaque(bool opaqueHint)
{
    setFlag(Blending, !opaqueHint);
}



/*!
    \internal
 */

QSGMaterialType *QSGVertexColorMaterial::type() const
{
    return &QSGVertexColorMaterialShader::type;
}



/*!
    \internal
 */

QSGMaterialShader *QSGVertexColorMaterial::createShader() const
{
    return new QSGVertexColorMaterialShader;
}

QT_END_NAMESPACE
