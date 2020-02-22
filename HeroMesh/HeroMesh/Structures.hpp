#pragma once

#include "Point2d.hpp"
#include "Point3d.hpp"
#include "Matrix3x3.hpp"
#include "Matrix3x4.hpp"
#include "StaticVector.hpp"

namespace HeroMesh
{

	struct Voxel;

	// TODO: Remove and replace with <aliceVision/types.hpp>
	typedef uint32_t IndexT;

	struct ImageParams
	{
		IndexT viewId;
		int width;
		int height;
		int size;
		std::string path;

		ImageParams(IndexT _viewId, int _width, int _height, std::string _path)
			: viewId(_viewId)
			, width(_width)
			, height(_height)
			, size(_width * _height)
			, path(_path)
		{}

		ImageParams& operator=(const ImageParams& param)
		{
			viewId = param.viewId;
			width = param.width;
			height = param.height;
			size = param.size;
			return *this;
		}
	};

	struct SortedId
	{
		int id;
		float value;

		SortedId() {}

		SortedId(int _id, float _value)
		{
			id = _id;
			value = _value;
		}

		SortedId& operator=(const SortedId& param)
		{
			id = param.id;
			value = param.value;
			return *this;
		}

		inline bool operator>(const SortedId& param) const
		{
			return (value > param.value);
		}

		inline bool operator<(const SortedId& param) const
		{
			return (value < param.value);
		}
	};

	int qSortCompareFloatAsc(const void* ia, const void* ib);
	int qSortCompareIntAsc(const void* ia, const void* ib);
	int qsortCompareSortedIdDesc(const void* ia, const void* ib);
	int qsortCompareSortedIdAsc(const void* ia, const void* ib);
	int qSortCompareVoxelByXAsc(const void* ia, const void* ib);
	int qSortCompareVoxelByYAsc(const void* ia, const void* ib);
	int qSortCompareVoxelByZAsc(const void* ia, const void* ib);
	int qSortComparePixelByXDesc(const void* ia, const void* ib);
	int qSortComparePixelByXAsc(const void* ia, const void* ib);

	struct IdValue
	{
		int id;
		float value;

		IdValue() {}

		IdValue(int _id, float _value)
		{
			id = _id;
			value = _value;
		}

		IdValue& operator=(const IdValue& param)
		{
			id = param.id;
			value = param.value;
			return *this;
		}

		inline bool operator>(const IdValue& param) const
		{
			return (value > param.value);
		}

		inline bool operator<(const IdValue& param) const
		{
			return (value < param.value);
		}
	};

	struct mv2DTriangle
	{
		int cam;
		Point2d pts[3];

		mv2DTriangle& operator=(const mv2DTriangle& m)
		{
			pts[0] = m.pts[0];
			pts[1] = m.pts[1];
			pts[2] = m.pts[2];
			cam = m.cam;
			return *this;
		}
	};

	struct CameraMatrices
	{
		Matrix3x4 P;
		Matrix3x3 R, K, iR, iK, iCam;
		Point3d C;
		float f, k1, k2;
	};

	int indexOfSortedVoxelArrByX(int val, StaticVector<Voxel>& values, int startId, int stopId);

} // namespace HeroMesh
