/*
 * Tiled Map Editor (Qt)
 * Copyright 2008 Tiled (Qt) developers (see AUTHORS file)
 *
 * This file is part of Tiled (Qt).
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <QMap>
#include <QString>

namespace Tiled {

class ObjectGroup;

/**
 * An object on a map.
 */
class MapObject
{
public:
    /**
     * Constructor.
     */
    MapObject(const QString &name, const QString &type,
              int x, int y, int width, int height);

    /**
     * Destructor.
     */
    ~MapObject() {}

    /**
     * Returns the name of this object.
     */
    const QString &name() const { return mName; }

    /**
     * Returns the x position of this object.
     */
    int x() const { return mX; }

    /**
     * Sets the x position of this object.
     */
    void setX(int x) { mX = x; }

    /**
     * Returns the y position of this object.
     */
    int y() const { return mY; }

    /**
     * Sets the x position of this object.
     */
    void setY(int y) { mY = y; }

    /**
     * Returns the width of this object.
     */
    int width() const { return mWidth; }

    /**
     * Sets the width of this object.
     */
    void setWidth(int width) { mWidth = width; }

    /**
     * Returns the height of this object.
     */
    int height() const { return mHeight; }

    /**
     * Sets the height of this object.
     */
    void setHeight(int height) { mHeight = height; }

    /**
     * Returns the type of object this is.
     */
    const QString &type() const { return mType; }

    /**
     * Set the property with the given name, and value.
     */
    void setProperty(const QString &name, const QString &value);

    /**
     * Returns a pointer to the properties of this object. This allows
     * modification of the properties.
     */
    QMap<QString, QString>* properties() { return &mProperties; }

    /**
     * Returns a copy of the properties of this object.
     */
    QMap<QString, QString> properties() const { return mProperties; }

    /**
     * Returns the object group this object belongs to.
     */
    ObjectGroup *objectGroup() const { return mObjectGroup; }

    /**
     * Sets the object group this object belongs to. Should only be called
     * from the ObjectGroup class.
     */
    void setObjectGroup(ObjectGroup *objectGroup)
    { mObjectGroup = objectGroup; }

private:
    QString mName;
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    QString mType;
    QMap<QString, QString> mProperties;
    ObjectGroup *mObjectGroup;
};

} // namespace Tiled

#endif // MAPOBJECT_H