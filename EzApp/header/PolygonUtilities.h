#pragma once
#ifndef POLYGON_UTILITIES_H
#define POLYGON_UTILITIES_H

// Inclusion des bibliothèques
#include <vector>


// This utility is not created for speed (really not efficient, glup... beurk... SOS).


namespace ezapp {

	//! \brief Cette classe utilitaire donne accès à quelques outils de calcul liés aux polygones.
	//!
	//! \detail Cette classe est un amalgame de plusieurs fonctions statiques 
	//! permettant de faire l'analyse de polygones. Dans tous les cas, les 
	//! polygones doivent être définis par un tableau de points (contigüs en 
	//! mémoire). Chaque point doivent être un aggrégat de deux "float" contigüs.
	//! 
	class PolygonUtilities
	{
	public:
		PolygonUtilities() = delete;
		PolygonUtilities(PolygonUtilities const&) = delete;
		PolygonUtilities& operator=(PolygonUtilities const&) = delete;
		~PolygonUtilities() = delete;


		//! \brief Applique une transformation affine sur le polygone : translation
		static void translate(size_t verticesCount, float * verticesRawBuffer, float x, float y);
		//! \brief Applique une transformation affine sur le polygone : rotation exprimée en radians
		static void rotate(size_t verticesCount, float * verticesRawBuffer, float rotationRadians);
		//! \brief Applique une transformation affine sur le polygone : homothétie
		static void scale(size_t verticesCount, float * verticesRawBuffer, float sc);
		//! \brief Applique une transformation affine sur le polygone : translation, rotation (radians) et homothétie
		static void transform(size_t verticesCount, float * verticesRawBuffer, float translationX, float translationY, float rotationRadians, float scale);


		// all verticesRawBuffer must be a contiguous array of two contiguous float organized such as a 2d point x-y (32 bits floating point)
		//! \brief Retourne l'aire d'un polygone.
		static float area(size_t verticesCount, float const* verticesRawBuffer);
		//! \brief Retourne le périmètre d'un polygone.
		static float perimeter(size_t verticesCount, float const* verticesRawBuffer);

		//! \brief Détermine si un point se trouve en contact avec le polygone.
		static bool containsPoint(size_t verticesCount, float const* verticesRawBuffer, float xPoint, float yPoint);
		//! \brief Détermine si un point se trouve en contact avec le polygone considérant une transformation affine pour le polygone et le point.
		static bool containsPoint(size_t verticesCount, float const* verticesRawBuffer, float translationPgX, float translationPgY, float rotationPg, float scalePg,
			float xPoint, float yPoint, float translationPtX = 0.0f, float translationPtY = 0.0f, float rotationPt = 0.0f, float scalePt = 1.0f);
		//! \brief Détermine s'il existe une intersection entre deux polygones.
		static bool intersectPolygon(size_t verticesCount1, float const* verticesRawBuffer1, size_t verticesCount2, float const* verticesRawBuffer2);
		//! \brief Détermine s'il existe une intersection entre deux polygones considérant une transformation affine pour le polygone et le point.
		static bool intersectPolygon(size_t verticesCount1, float const* verticesRawBuffer1, float translationPg1X, float translationPg1Y, float rotationPg1, float scalePg1,
			size_t verticesCount2, float const* verticesRawBuffer2, float translationPg2X, float translationPg2Y, float rotationPg2, float scalePg2);

		// all vector must be of an aggregate type (t) of two contiguous float organized such as a 2d point x-y (struct, class, fundamental array, ...)
		//! \brief Applique une transformation affine sur le polygone : translation
		template <typename t> static void translate(std::vector<t> & polygon, float x, float y);
		//! \brief Applique une transformation affine sur le polygone : rotation exprimée en radians
		template <typename t> static void rotate(std::vector<t> & polygon, float rotationRadians);
		//! \brief Applique une transformation affine sur le polygone : homothétie
		template <typename t> static void scale(std::vector<t> & polygon, float sc);
		//! \brief Applique une transformation affine sur le polygone : translation, rotation (radians) et homothétie
		template <typename t> static void transform(std::vector<t> & polygon, float translationX, float translationY, float rotationRadians, float scale);

		//! \brief Retourne l'aire d'un polygone.
		template <typename t> static float area(std::vector<t> const& polygon);
		//! \brief Retourne le périmètre d'un polygone.
		template <typename t> static float perimeter(std::vector<t> const& polygon);

		//! \brief Détermine si un point se trouve en contact avec le polygone.
		template <typename t> static bool containsPoint(std::vector<t> const& polygon, float xPoint, float yPoint);
		//! \brief Détermine si un point se trouve en contact avec le polygone considérant une transformation affine pour le polygone et le point.
		template <typename t> static bool containsPoint(std::vector<t> const& polygon, float translationPgX, float translationPgY, float rotationPg, float scalePg,
			float xPoint, float yPoint, float translationPtX = 0.0f, float translationPtY = 0.0f, float rotationPt = 0.0f, float scalePt = 1.0f);

		//! \brief Détermine s'il existe une intersection entre deux polygones.
		template <typename t> static bool intersectPolygon(std::vector<t> const& polygon1, std::vector<t> const& polygon2);
		//! \brief Détermine s'il existe une intersection entre deux polygones considérant une transformation affine pour le polygone et le point.
		template <typename t> static bool intersectPolygon(std::vector<t> const& polygon1, float translationPg1X, float translationPg1Y, float rotationPg1, float scalePg1,
			std::vector<t> const& polygon2, float translationPg2X, float translationPg2Y, float rotationPg2, float scalePg2);
	};





































	template<typename t>
	inline void PolygonUtilities::translate(std::vector<t> & polygon, float x, float y)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::translate : t must be an aggregate of two float.");
		translate(polygon.size(), reinterpret_cast<float*>(polygon.data()), x, y);
	}

	template<typename t>
	inline void PolygonUtilities::rotate(std::vector<t> & polygon, float rotationRadians)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::rotate : t must be an aggregate of two float.");
		rotate(polygon.size(), reinterpret_cast<float*>(polygon.data()), rotationRadians);
	}

	template<typename t>
	inline void PolygonUtilities::scale(std::vector<t> & polygon, float sc)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::scale : t must be an aggregate of two float.");
		scale(polygon.size(), reinterpret_cast<float*>(polygon.data()), sc);
	}

	template<typename t>
	inline void PolygonUtilities::transform(std::vector<t> & polygon, float translationX, float translationY, float rotationRadians, float scale)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::transform : t must be an aggregate of two float.");
		transform(polygon.size(), reinterpret_cast<float*>(polygon.data()), translationX, translationY, rotationRadians, scale);
	}

	template<typename t>
	inline float PolygonUtilities::area(std::vector<t> const& polygon)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::area : t must be an aggregate of two float.");
		return area(polygon.size(), reinterpret_cast<float const*>(polygon.data()));
	}

	template<typename t>
	inline float PolygonUtilities::perimeter(std::vector<t> const& polygon)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::perimeter : t must be an aggregate of two float.");
		return perimeter(polygon.size(), reinterpret_cast<float const*>(polygon.data()));
	}

	template<typename t>
	inline bool PolygonUtilities::containsPoint(std::vector<t> const& polygon, float xPoint, float yPoint)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::containsPoint : t must be an aggregate of two float.");
		return containsPoint(polygon.size(), reinterpret_cast<float const*>(polygon.data()), xPoint, yPoint);
	}

	template<typename t>
	inline bool PolygonUtilities::containsPoint(std::vector<t> const& polygon, float translationPgX, float translationPgY, float rotationPg, float scalePg, float xPoint, float yPoint, float translationPtX, float translationPtY, float rotationPt, float scalePt)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::containsPoint : t must be an aggregate of two float.");
		return containsPoint(polygon.size(), reinterpret_cast<float const*>(polygon.data()), translationPgX, translationPgY, rotationPg, scalePg,
			xPoint, yPoint, translationPtX, translationPtY, rotationPt, scalePt);
	}

	template<typename t>
	inline bool PolygonUtilities::intersectPolygon(std::vector<t> const& polygon1, std::vector<t> const& polygon2)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::intersectPolygon : t must be an aggregate of two float.");
		return intersectPolygon(polygon1.size(), reinterpret_cast<float const*>(polygon1.data()), polygon2.size(), reinterpret_cast<float const*>(polygon2.data()));
	}

	template<typename t>
	inline bool PolygonUtilities::intersectPolygon(std::vector<t> const& polygon1, float translationPg1X, float translationPg1Y, float rotationPg1, float scalePg1, std::vector<t> const& polygon2, float translationPg2X, float translationPg2Y, float rotationPg2, float scalePg2)
	{
		static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in PolygonUtilities::intersectPolygon : t must be an aggregate of two float.");
		return intersectPolygon(polygon1.size(), reinterpret_cast<float const*>(polygon1.data()), translationPg1X, translationPg1Y, rotationPg1, scalePg1,
			polygon2.size(), reinterpret_cast<float const*>(polygon2.data()), translationPg2X, translationPg2Y, rotationPg2, scalePg2);
	}

}

#endif // POLYGON_UTILITIES_H