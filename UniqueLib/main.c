#include <stdio.h>
#include <stdlib.h>


#include"defines.h"
#include"menu.h"
#include"create.h"
#include"my_var.h"
#include"save_data.h"
#include"sort_data.h"
#include"modify.h"
#include"load_data.h"
#include"about.h"
#include"show_data.h"
/*


#include"details.h"
*/


/**-----------------------------------------------------------------------*/
/** Project: Library_Manager                                              */
/** Date   : 03/04/2011                                                   */
/** programmeur: Someone!                                                 */
/** ----------------------------------------------------------------------*/

/**************************************************************************/
//                        Les Variables

char choix;
int done=1;

/**************************************************************************/




    int main()
{

restauration();

    while(done)
    {

       choix=menu();

       switch (choix)
            {
                case '1':
                menu3();
                break;

                case '2':
                menu1();
                break;

                case '3':
              //  modifier();
                break;

                case '4':
                about();
                break;

                case '5':
                done=0;
                break;

                default:
                gotoxy(15,30);
                printf("Mauvais choix!\n");
                Sleep(500);
                break;
            }
    }


    return EXIT_SUCCESS;
}
