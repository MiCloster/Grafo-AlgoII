#include <string>

#include "menu.h"
using namespace std;

int main() {

   Menu *nuevoMenu = new Menu();

   nuevoMenu -> cargarDatos();
   nuevoMenu -> menuCiudades();

   nuevoMenu -> cargarGrafo();
   nuevoMenu -> menuRutas();

   delete nuevoMenu;
   

   return 0;
}
