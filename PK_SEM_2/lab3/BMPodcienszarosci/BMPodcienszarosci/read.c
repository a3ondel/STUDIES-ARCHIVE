#include "read.h"


int read_file(char *filename, BMP *img)
{
	int error_code = 0;
	FILE *file;
	file = fopen(filename, "rb");
	if (file)
	{
		if (read_filehead(file, &img->fhead)&& read_imghead(file, &img->imghead))
		{
			read_array(file, img);
			error_code = 1;
		}
		else
			error_code = 0;//zly format pliku

		 fclose(file);
		return error_code;
	}
	return -1;//nie udalo sie otworzyc pliku

}

int read_filehead(FILE *file, FILEHEADER *head)
{
	fread(head, sizeof(FILEHEADER), 1, file); 
	if (head->signature[0] == 'B'&&head->signature[1] == 'M')
		return 1;//dobry format
	else
		return 0; //zly format
}


int read_imghead(FILE *file, IMGHEADER *head)
{
	fread(head, sizeof(IMGHEADER), 1, file); 

	if (head->bit_count == 24) //sprawdzanie czy obraz jest 24 bitowy
	{
		if (head->header_size == sizeof(IMGHEADER))
			return 1; //obslugiwany plik
		else
			return 0;//nie obslugiwany typ
	}
	else
		return 0;//nie obslugiwany typ

}



void read_array( FILE *file, BMP *img)
{

	char paddingcan[3] = { 0,0,0 }; //tablica na padding
	int padding = get_padding((int)img->imghead.width_px);
	
	img->imgarray = (PIXEL*)malloc(img->imghead.width_px *img->imghead.height_px*sizeof(PIXEL)); //rezerwowanie pamieci 

	fseek(file, (long)img->fhead.offset, SEEK_SET);

	for ( int i = 0;  i < (int)img->imghead.height_px;  i++)
	{
		fread(&(img->imgarray[i*img->imghead.width_px]), sizeof(PIXEL), img->imghead.width_px, file);
		fread(paddingcan, sizeof(char), padding, file);
	}


}

