#pragma once
#ifndef _EZAPP_KEYBOARD_H_
#define _EZAPP_KEYBOARD_H_


// Inclusion des bibliothèques
#include <cstdint>


// Déclaration du namespace ezapp
namespace ezapp {

    //! \brief Classe permettant de connaître l'état du clavier.
    class Keyboard
    {
    public:
        //! Type énumérant les touches du claviers pouvant être détectées
        //! \hideinitializer
        enum class Key : int32_t {
            Unknown = -1, //!< \hideinitializer Non utilisé
            A = 0, //!< \hideinitializer Lettre A (insensible à la casse)
            B, //!< Lettre B (insensible à la casse)
            C, //!< Lettre C (insensible à la casse)
            D, //!< Lettre D (insensible à la casse)
            E, //!< Lettre E (insensible à la casse)
            F, //!< Lettre F (insensible à la casse)
            G, //!< Lettre G (insensible à la casse)
            H, //!< Lettre H (insensible à la casse)
            I, //!< Lettre I (insensible à la casse)
            J, //!< Lettre J (insensible à la casse)
            K, //!< Lettre K (insensible à la casse)
            L, //!< Lettre L (insensible à la casse)
            M, //!< Lettre M (insensible à la casse)
            N, //!< Lettre N (insensible à la casse)
            O, //!< Lettre O (insensible à la casse)
            P, //!< Lettre P (insensible à la casse)
            Q, //!< Lettre Q (insensible à la casse)
            R, //!< Lettre R (insensible à la casse)
            S, //!< Lettre S (insensible à la casse)
            T, //!< Lettre T (insensible à la casse)
            U, //!< Lettre U (insensible à la casse)
            V, //!< Lettre V (insensible à la casse)
            W, //!< Lettre W (insensible à la casse)
            X, //!< Lettre X (insensible à la casse)
            Y, //!< Lettre Y (insensible à la casse)
            Z, //!< Lettre Z (insensible à la casse)
            Num0, //!< Nombre 0 (du clavier standard alphanumérique)
            Num1, //!< Nombre 1 (du clavier standard alphanumérique)
            Num2, //!< Nombre 2 (du clavier standard alphanumérique)
            Num3, //!< Nombre 3 (du clavier standard alphanumérique)
            Num4, //!< Nombre 4 (du clavier standard alphanumérique)
            Num5, //!< Nombre 5 (du clavier standard alphanumérique)
            Num6, //!< Nombre 6 (du clavier standard alphanumérique)
            Num7, //!< Nombre 7 (du clavier standard alphanumérique)
            Num8, //!< Nombre 8 (du clavier standard alphanumérique)
            Num9, //!< Nombre 9 (du clavier standard alphanumérique)
            Escape,     //!< Touche d'échappement (escape)
            LControl,   //!< Touche controle de gauche (left control)
            LShift,     //!< Touche "shift" de gauche (left shift)
            LAlt,       //!< Touche alternative de gauche (left alt)
            LSystem,    //!< Touche système de gauche (left system)
            RControl,   //!< Touche controle de droite (right control)
            RShift,     //!< Touche "shift" de droite (right shift)
            RAlt,       //!< Touche alternative de droite (right alt)
            RSystem,    //!< Touche système de droite (right system)
            Menu,       //!< Touche menu
            LBracket,   //!< Symbole accolade droite de gauche : [ 
            RBracket,   //!< Symbole accolade droite de droite : ]
            Semicolon,  //!< Symbole point-virgule : ;
            Comma,      //!< Symbole virgule : ,
            Period,     //!< Symbole point : .
            Quote,      //!< Symbole guillemet : "
            Slash,      //!< Symbole barre oblique : /
            Backslash,  //!< Symbole barre oblique inverse
            Tilde,      //!< Symbole tilde : ~
            Equal,      //!< Symbole d'égalité : =
            Hyphen,     //!< Symbole trait d'union : -
            Space,      //!< Barre d'espacement
            Enter,      //!< Saut de ligne
            Backspace,  //!< Retour arrière
            Tab,        //!< Tabulation
            PageUp,     //!< Page précédente
            PageDown,   //!< Page suivante
            End,        //!< Fin
            Home,       //!< Début
            Insert,     //!< Insertion
            Delete,     //!< Suppression
            Add,        //!< Symbole mathématique d'addition : +
            Subtract,   //!< Symbole mathématique de soustraction : -
            Multiply,   //!< Symbole mathématique de multiplication : *
            Divide,     //!< Symbole mathématique de division : /
            Left,       //!< Flèche vers la gauche
            Right,      //!< Flèche vers la droite
            Up,         //!< Flèche vers le haut
            Down,       //!< Flèche vers le bas
            Numpad0,    //!< Nombre 0 du clavier numérique
            Numpad1,    //!< Nombre 1 du clavier numérique
            Numpad2,    //!< Nombre 2 du clavier numérique
            Numpad3,    //!< Nombre 3 du clavier numérique
            Numpad4,    //!< Nombre 4 du clavier numérique
            Numpad5,    //!< Nombre 5 du clavier numérique
            Numpad6,    //!< Nombre 6 du clavier numérique
            Numpad7,    //!< Nombre 7 du clavier numérique
            Numpad8,    //!< Nombre 8 du clavier numérique
            Numpad9,    //!< Nombre 9 du clavier numérique
            F1,         //!< Touche de fonction 1
            F2,         //!< Touche de fonction 2
            F3,         //!< Touche de fonction 3
            F4,         //!< Touche de fonction 4
            F5,         //!< Touche de fonction 5
            F6,         //!< Touche de fonction 6
            F7,         //!< Touche de fonction 7
            F8,         //!< Touche de fonction 8
            F9,         //!< Touche de fonction 9
            F10,        //!< Touche de fonction 10
            F11,        //!< Touche de fonction 11
            F12,        //!< Touche de fonction 12
            F13,        //!< Touche de fonction 13
            F14,        //!< Touche de fonction 14
            F15,        //!< Touche de fonction 15
            Pause,      //!< Pause
            
            // énumération technique, ne devrait pas être utilisé
            __count__   //!< \hideinitializer
        };

        bool isKeyPressed(Key key) const; //!< Retourne vrai si la touche demandée est appuyée sinon retourne faux.

    private:
        Keyboard() = default;
        Keyboard(Keyboard const &) = delete;
        Keyboard(Keyboard &&) = delete;
        Keyboard& operator=(Keyboard const &) = delete;
        Keyboard& operator=(Keyboard &&) = delete;
        ~Keyboard() = default;

        friend class Application;
    };

}

#endif // _EZAPP_KEYBOARD_H_