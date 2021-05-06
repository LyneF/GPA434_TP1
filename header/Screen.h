#pragma once
#ifndef _EZAPP_SCREEN_H_
#define _EZAPP_SCREEN_H_


// Inclusion des bibliothèques
#include <memory>
#include <vector>
#include <string>


// Déclaration du namespace ezapp
namespace ezapp {
    
    class Application;

    //! \brief Permet de dessiner à l'écran.
    //! 
    //! \detail La classe Screen permet de dessiner sur l'écran très simplement des polygones ou du texte.
    //! 
    //! Les étapes suggérées pour dessiner un polygon :
    //!     -# setPen/setNoPen       défini la couleur et l'épaisseur du contour
    //!     -# setBrush/setNoBrush   défini la couleur du remplissage
    //!     -# setPolygonVertices    détermine les sommets du polygone à dessiner
    //!     -# drawPolygon           dessine le polygone en appliquant les transformations affines données
    //! 
    //! Les étapes suggérées pour dessiner du texte :
    //!     -# setPen/setNoPen       défini la couleur et l'épaisseur du contour
    //!     -# setBrush/setNoBrush   défini la couleur du remplissage
    //!     -# setTextFont           (optionnellement) détermine la police de caractères à utiliser (n'est pas à redéfinir si on utilise la même police)
    //!     -# setTextStyle          (optionnellement - attention, ne fonctionne pas entièrement) détermine les styles de la police : gras - italique - souligné - barré
    //!     -# setTextSizes          (optionnellement) détermine les tailles reliées à la police de caractères
    //!     -# drawText              dessine le texte (applique les transformations affines données)
    class Screen
    {
    public:
        enum class TextPosition { BaseLeft, TopLeft, CenterLeft, BottomLeft, TopCenter, Center, BottomCenter, TopRight, CenterRight, BottomRight };

        size_t width() const;  //!< Retourne la largeure de l'écran.
        size_t height() const; //!< Retourne la hauteur de l'écran.

        void setNoPen();    //!< Détermine qu'il n'y a pas de contour. Le crayon est considéré transparent.
        void setPen(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f, float width = 1.0f);   //!< Détermine la couleur et l'épaisseur du contour
        void setNoBrush();  //!< Détermine qu'il n'y a pas de remplissage. La brosse est considérée transparente.
        void setBrush(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f); //!< Détermine la couleur du remplissage

        
        void clear();       //!< Effectue un remplissage complet du fond de l'écran de la couleur de remplissage (brush).
        
        //! \brief Détermine le polygone à dessiner (ne le dessine pas). 
        //! \param[in] verticesCount        Le nombre de sommets du polygone
        //! \param[in] verticesRawBuffer    Le tableau contenant les coordonnées du polygone - le format du tableau DOIT correspondre à une suite de verticesCount fois 2 float. Tout autre représentation du tableau donne un comportement imprévisible.
        void setPolygonVertices(size_t verticesCount, float const * verticesRawBuffer); 
        //! \brief Détermine le polygone à dessiner (ne le dessine pas). 
        //! \param[in] vertices Le tableau correspondant à la liste des sommets. Le format de t DOIT être une suite de 2 float contigüs.
        template <typename t>
        void setPolygonVertices(std::vector<t> const & vertices);
        //! \brief Dessine le polygone déterminé par les fonctions setPolygonVertices. 
        //! \detail Si aucun polygone n'est défini, la fonction ne fait rien. De plus, l'affichage est réalisé selon la transformation affine des paramètres données.
        //! \param[in] x, y Translation de l'affichage
        //! \param[in] rotation Rotation de l'affichage en radians
        //! \param[in] scale Homothétie de l'affichage (scaling)
        void drawPolygon(float x = 0.0f, float y = 0.0f, float rotation = 0.0f, float scale = 1.0f);

        //! \brief Détermine la police de caractères à utiliser. La chaîne de caractères doit correspondre à une police qui aura été chargée dans l'application. 
        bool setTextFont(std::string const & fontName);
        //! \brief Détermine certaines caractéristiques de taille sur la police de caractères.
        void setTextSizes(size_t characterSize = 30, float letterSpacingRatio = 1.0f, float lineSpacingRatio = 1.0f);
        //! \brief Détermine certains styles sur la police de caractères. ATTENTION - cette fonction n'est pas entièrement fonctionnelle!
        void setTextStyle(bool bold = false, bool italic = false, bool underline = false, bool strikeThrough = false); // to do : incomplete - not working
        //! \brief Dessine le texte donné. 
        //! \param[in] text Le texte à afficher
        //! \param[in] x, y Translation de l'affichage
        //! \param[in] rotation Rotation de l'affichage en radians
        //! \param[in] scale Homothétie de l'affichage (scaling)
        //! \param[in] position Position relative du texte aux coordonnées données
        void drawText(std::string const & text, float x, float y, float rotation = 0.0f, float scale = 1.0f, TextPosition position = TextPosition::BaseLeft);

        //! \brief Retourne la boîte capable du texte donné (la boîte capable se nomme "bounding box" en anglais). 
        //! \param[out] left, top, right, bottom Les frontières de la boîte capable.
        //! \param[in] text Le texte à afficher
        //! \param[in] x, y Translation de l'affichage
        //! \param[in] rotation Rotation de l'affichage en radians
        //! \param[in] scale Homothétie de l'affichage (scaling)
        //! \param[in] position Position relative du texte aux coordonnées données
        void getTextBounds(float & left, float & top, float & right, float & bottom, std::string const & text, float x, float y, float rotation = 0.0f, float scale = 1.0f, TextPosition position = TextPosition::BaseLeft);

        //! Retourne le nom de la police de caractères courante.
        std::string currentFont() const;

    private:
        Screen(Application & app);
        Screen(Screen const &) = delete;
        Screen(Screen &&) = delete;
        Screen& operator=(Screen const &) = delete;
        Screen& operator=(Screen &&) = delete;
        ~Screen();

        class Impl;
        std::unique_ptr<Impl> mImpl;

        friend class Application;
    };





    template <typename t>
    void Screen::setPolygonVertices(std::vector<t> const & vertices)
    {
        static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in Screen::setPolygonVertices : t must be an aggregate of two float.");
        setPolygonVertices(vertices.size(), reinterpret_cast<float const *>(vertices.data()));
    }



}

#endif // _EZAPP_SCREEN_H_