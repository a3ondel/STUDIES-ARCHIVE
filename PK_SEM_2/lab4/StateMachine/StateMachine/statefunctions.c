#include <stdio.h>
#include "statefunctions.h"
#include "utility.h"



/*
funkcja uruchamiajaca odpowiednie stany 
*/
state_t run_state(state_t curr_state, coffe_machine *data, state_func_t **const state_table)
{

	return state_table[curr_state](data);
}


/*
stan kiedy cos poszlo nie tak
*/
state_t do_state_error(coffe_machine *data)
{
	printf_s("Zepsute czujniki(problemzplikiem)");
	system("pause");
	return ST_EXIT;

}

/*
ladowanie infomacji z pliku i "przejscie" do odpowiedniego stanu
*/
state_t do_state_initial(coffe_machine *data)
{

	FILE *file;
	file = fopen("resources.txt", "r");

	if (file != NULL)
	{
		
		printf_s("Uruchamianie ekspresu");
		fileload(file, data); //wczytywanie informacji z pliku
		
		fclose(file);
		return ST_WAIT_4_USER;

	}
	else
		return ST_ERROR;


}

/*
oczekiwanie na wcisniecie odpowiedniego klawisza
i uruchomienie odpowiedniego stanu
*/
state_t do_state_wait_4_user(coffe_machine *data) 
{
	char tmp;
	printmenu(); //wypisywanie menu
	do
	{
		tmp = getch();
	} while (tmp<'1' || tmp>'8'); //pobieranie odpowiedniego znaku
	
	switch (tmp) //przechodzenie do wybranego stanu
	{
	case '1': 
		return ST_SMALLCOFEE;
	case '2':
		return ST_BIGCOFFE;
	case '3':
		return ST_ESPRESSO;
	case '4':
		return ST_CAPPUCINO;
	case '5':
		return ST_HOTMILK;
	case '6':
		return ST_COFFEPOWERSET;
	case '7':
		return ST_BASEWATERSET;

	case '8':
		return ST_EXIT;
	}
	
	
}
/*
zapis do pliku i wylaczenie ekspresu
*/
state_t do_state_exit(coffe_machine *data)
{
	FILE *file;
	file = fopen("resources.txt", "w"); //zapis ustawien i informacji o zasobach do pliku
	if (file != NULL)
	{
		filesave(file, data); //zapis informacji o zasobach i ustawien do pliku
		cls();
		printf_s("Ekspres wylacza sie");

		Sleep(2000);
		fclose(file);

		return ST_OFF;
	}
	else
		return ST_ERROR;
}
