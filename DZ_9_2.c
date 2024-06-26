/* В файле .txt дана символьная строка не более 1000 символов. 
 * Необходимо заменить все буквы "а" на буквы "b" и наоборот, 
 * как заглавные, так и строчные. Результат записать в .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов.
Данные на выходе: Строка из маленьких и больших английских
букв, знаков препинания и пробелов. */

#include <stdio.h>
#include <string.h>

const int line_width = 1024; // задаём константу 

int main(void) {
	FILE *f;
	f=fopen("input.txt", "w"); // открытие файла на запись
	fprintf(f, "%s", "aabbccddABCD"); // в файл записываем строку
	fclose(f); // закрываем файл
	
	char * input_fn = "input.txt"; //Задаём имя текстового файла
	char * output_fn = "output.txt"; //Задаём имя текстового файла
	char line[line_width];//Задаём символьный массив длиной line_width
	FILE *fp;
	fp = fopen(input_fn, "r");// открываем файл "input.txt" на чтение
	fscanf(fp, "%[^\n]", line);// считываем в массив содержимое файла  
	fclose(fp); // закрываем файл
	char c; // задаём символьную переменную
	int i = 0; // задаём числовую переменную
	while ((c = line[i]) != '\0') { //пока не достигнут конец файла
		if ((c == 'a') || (c == 'A')) // если код текущего символа 
		//равен коду маленькой или большой буквы а,
			line[i] += 1; // увеличить код текущего символа на 1 a->b
		else if ((c == 'b') || (c == 'B'))// если код текущего символа 
		//равен коду маленькой или большой буквы в,
			line[i] -= 1;// увеличить код текущего символа на 1 b->a
	i++; //декремент счётчика
	}
	fp = fopen(output_fn, "w");// открыть (создать) файл на запись
	fprintf(fp, "%s", line);// записать символьный массив в файл
	fclose(fp);// закрыть файл
	return 0;// возвратить 0 — признак успешного завершения программы
}
