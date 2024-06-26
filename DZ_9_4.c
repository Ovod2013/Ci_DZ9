/* В файле .txt строка из маленьких и больших английских букв, знаков
препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
все пробелы. Результат записать в файл .txt. */

#include <stdio.h>



int main(void) {
	FILE *f;
	f=fopen("input.txt", "w"); // открытие файла на запись
	fprintf(f, "%s", "abc cde def"); // в файл записываем строку
	fclose(f); // закрываем файл
	
	FILE *f_in = fopen("input.txt", "r");// открыть файл на чтение
	FILE *f_out = fopen("output.txt", "w");// Открыть файл на запись
	char str1[1002];
	int j;
	char c;
	int i = -1;
	fgets(str1, 1000, f_in);// читает символы из файла "input.txt" 
			//и записывает в массив str1, к конце пишет нулевой символ
	fclose(f_in); //закрыть файл
	while (str1[++i] != '\0'){ // обойти массив от начала 
								//до нулевого символа
		c = str1[i]; 
		j = i;
		while(str1[++j] != '\0')// обойти все оставшиеся символы 
			if (str1[j] == c)// если символ повторяется
				str1[j] = ' ';// заменить его на пробел
	}
	i = -1;
	while (str1[++i] != '\0')// обойти массив от начала 
								//до нулевого символа
		if (str1[i] != ' ')// если встретился пробел, пропустить его,
			fprintf(f_out, "%c", str1[i]);// остальные символы 
										//записать в файл
	fclose(f_out);//закрыть файл
	return 0;// возвратить 0 — признак успешного завершения программы
}
