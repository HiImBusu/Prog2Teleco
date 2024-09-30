// 1. Si no esta definido ya el modulo en nuestra compilacion, lo metemos (siempre lo pondremos y generalmente nos lo daran hecho en la plantilla)
#ifndef __MODULO__H
#define __MODULO__H

// 2. Bibliotecas que necesitemos DENTRO de este modulo
#include <string>

// 2. Para que no haya conflictos de nombres entre distintos modulos generalmente TODAS nuestras definiciones y funciones las encapsularemos dentro de un espacio de nombres nuevo
namespace Unitec{
    // -- Parte que tendremos que rellenar --
    // 3. Definiciones de tipos
    typedef struct{
        std::string nombre; // Para tipos de datos complejos (string, array) tendremos que especificar que estan definidos en el espacio de nombres "std" (estandar).
        int edad;
    }TPersona;

    // 4. DEFINICION de funciones
    void leerPersona(TPersona& p); // Leemos los datos de la persona por consola y devolvemos un TPersona relleno
    void imprimirPersona(const TPersona& p); // Mostramos los datos de la persona por pantalla
    int suma(int a, int b); // Funcion que suma dos numeros enteros
}

#endif