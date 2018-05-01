/*
 * GeometryUtil.h
 *
 *  Created on: 27 Απρ 2018
 *      Author: Synodiporos
 */

#ifndef GEOMETRY_GEOMETRYUTIL_H_
#define GEOMETRY_GEOMETRYUTIL_H_
#include "Coordinates.h"
#include <stdint.h>

class GeometryUtil {
public:
	GeometryUtil();
	virtual ~GeometryUtil();

	static Coordinates* indexToCoordinates(
			unsigned short int i, uint8_t columns);
	static unsigned short int coordinatesToIndex(
			Coordinates* coords, uint8_t columns);
};

#endif /* GEOMETRY_GEOMETRYUTIL_H_ */
