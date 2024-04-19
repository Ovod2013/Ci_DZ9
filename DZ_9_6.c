/* В файле .txt дано предложение. Необходимо определить, сколько слов
заканчиваются на букву 'а'. Ответ записать в файл .txt. */

#include <stdio.h>
#include <string.h>

const int line_width = 1024;

int main(void) {
	FILE *f;
	f=fopen("input.txt", "w"); // открытие файла на запись
	fprintf(f, "%s", "Mama mila ramu"); // в файл записываем строку
	fclose(f); // закрываем файл
	
	char line[line_width]; // объявляем массив длиной 1024
	int count = 0;// объявляем переменную
	f = fopen("input.txt", "r");// открываем файл на чтение
	while (fscanf(f, "%s", line) == 1)//читаем из файла, 
									//пока не останется 1 символ
		if (line[strlen(line) - 1] == 'a')// сравниваем 
									//предпоследний символ с а
			count++;// если совпадает, увеличиваем счётчик на 1
	fclose(f);// закрываем файл
	f = fopen("output.txt", "w");// открываем (создаём) 
								//файл "output.txt" на запись
	fprintf(f, "%d", count);// записываем количество в файл
	fclose(f);//закрываем файл
	return 0;
}
