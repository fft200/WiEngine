/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "wyGrid3DAction.h"
#include "wyNode.h"
#include "wyGrid3D.h"
#include <typeinfo>

wyBaseGrid* wyGrid3DAction::makeGrid() {
	wyNode* t = getTarget();
	return wyGrid3D::make(t->getWidth(), t->getHeight(), m_gridX, m_gridY);
}

bool wyGrid3DAction::isGridReusable(wyBaseGrid* grid) {
	return typeid(*grid) == typeid(wyGrid3D);
}

wyGrid3DAction::~wyGrid3DAction() {
}

wyGrid3DAction::wyGrid3DAction(float duration, float gridX, float gridY) : wyGridAction(duration, gridX, gridY) {
}

wyVertex3D wyGrid3DAction::getVertex(wyDimension pos) {
	wyGrid3D* g = (wyGrid3D*)m_target->getGrid();
	return g->getVertex(pos);
}

wyVertex3D wyGrid3DAction::getOriginalVertex(wyDimension pos) {
	wyGrid3D* g = (wyGrid3D*)m_target->getGrid();
	return g->getOriginalVertex(pos);
}

void wyGrid3DAction::setVertex(wyDimension pos, wyVertex3D vertex) {
	wyGrid3D* g = (wyGrid3D*)m_target->getGrid();
	g->setVertex(pos, vertex);
}
