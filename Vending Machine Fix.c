#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//deklarasi universal
int minuman;
int hargaminuman=0;
int tot,i,num;
int kembalian;
int cash[7] = {1000, 2000, 5000, 10000, 20000, 50000, 100000};
int stock[10] = {3000, 4000, 5000, 5000, 5000, 7000, 7000, 9000, 9500, 9500};
int jumlah, jumlah1, jumlahn;
int total;

int menu();
int akhir();
int beli();
int keluar();
int help();
void listmenu();
int uang1();
int uang2();
int nambah();


struct menu
{
	char merk[20];
	char price[20];
};

struct temp
{
	char merk[20];
	char price[20];
};

struct menu Minuman[11];
struct menu dibeli[10];

// main code
int main ()
{	system("cls");
	strcpy( Minuman[1].merk, "Aqua");
   	strcpy( Minuman[1].price, "3.000,00");

	strcpy( Minuman[2].merk, "Milo 200ml");
  	strcpy(Minuman[2].price, "4.000,00");

  	strcpy( Minuman[3].merk, "Coca-Cola ");
   	strcpy(Minuman[3].price, "5.000,00");

   	strcpy( Minuman[4].merk, "Sprite");
   	strcpy(Minuman[4].price, "5.000,00");

    strcpy( Minuman[5].merk, "Fanta");
   	strcpy(Minuman[5].price, "5.000,00");

   	strcpy( Minuman[6].merk, "Larutan Penyegar");
   	strcpy(Minuman[6].price, "7.000,00");

   	strcpy( Minuman[7].merk, "Good Day Mocha");
   	strcpy(Minuman[7].price, "7.000,00");

   	strcpy( Minuman[8].merk, "L-Men 250ml");
   	strcpy(Minuman[8].price, "9.000,00");

   	strcpy( Minuman[9].merk, "Milo Kaleng");
   	strcpy(Minuman[9].price, "9.500,00");

   	strcpy(Minuman[10].merk, "Nescafe");
   	strcpy(Minuman[10].price, "9.500,00");

	printf("\n=========================================================================\n");
	printf("||                 SELAMAT DATANG DI VENDING MACHINE                    ||\n");
	printf("||                        Kelompok Hungry Hors                          ||\n");
	printf("||                   Teuku Alif Rafi Akbar - 1806195223                 ||\n");
	printf("||               	Umar Reksoprodjo - 1806195066                   ||\n");
	printf("=========================================================================\n\n");
	printf("-------------------------------------------------------------------------\n");
	printf("                     Menu mana yang Anda ingin pilih? \n");
	printf("-------------------------------------------------------------------------\n");

	printf("\n1. Start\n");
	printf("2. Help\n");
	printf("3. Exit\n");
	printf("4. Menu List\n");

	switch(getch())
	{
		case '1': system("cls");
					menu ();
						break;
		case '2': system("cls");
					help();
						break;
		case '3': system("cls");
					keluar();
						break;
		case '4': system("cls");
		   	listmenu();
		   	printf("\npress anything to continue...");
	   		getchar();
	   		main();
		default: system("cls");
				printf("ERROR! Wrong Input! Tolong pilih lagi\n\n");
					 main();
					 	break;
	}
}

// fungsi memulai transaksi
int menu ()
{
	printf("\n======================================================================================");
	printf("\n\n               Tekan tombol apapun untuk memulai transaksi\n\n");
	printf("======================================================================================\n\n");

	switch(getch())
	{
		default: uang1();
				break;
	}
}

int sort(struct menu *menu, int tot){
	//variable declaration
	int i, j;
	struct menu temp;

	//sort data
	for (i = 0; i < tot-1; i++){
		for (j = i+1; j < tot; j++){
			// if (strcmp(dibeli[i].price,dibeli[j].price)>0){
			if (strcmp(dibeli[i].price,dibeli[j].price)>0){
				// printf("%d",strcmp(menu[i].price,menu[j].price));
				temp=dibeli[i];
				dibeli[i]=dibeli[j];
				dibeli[j]=temp;
			}
		}
	}
}

void listmenu(){
	system("cls");
	printf ("Daftar Menu\n\n");
   			for(i=1;i<11;i++){
   				printf("%d.%s\n Rp %s \n",i,Minuman[i].merk, Minuman[i].price);
	   		}
}

// Fungsi Input Uang 1
int uang1()
{
	printf("Pilih nominal uang yang ingin dimasukkan!\n\n");
	printf("1.  Rp 1,000.00\n");
	printf("2.  Rp 2,000.00\n");
	printf("3.  Rp 5,000.00\n");
	printf("4.  Rp 10,000.00\n");
	printf("5.  Rp 20,000.00\n");
	printf("6.  Rp 50,000.00\n");
	printf("7.  Rp 100,000.00\n");

	switch(getch())
	{
		case '1': jumlah = cash[0];
			nambah();
					break;
		case '2': jumlah = cash[1];
			nambah();
					break;
		case '3': jumlah = cash[2];
			nambah();
					break;
		case '4': jumlah = cash[3];
			nambah();
					break;
		case '5': jumlah = cash[4];
			nambah();
					break;
		case '6': jumlah = cash[5];
			nambah();
					break;
		case '7': jumlah = cash[6];
			nambah();
					break;

		default: system("cls");
				printf("ERROR! Silahkan pilih kembali\n\n");
				uang1();
				break;
	}
}

//Fungsi Menu Nambah
int nambah()
{
	system("cls");
	printf("Apakah anda ingin memasukkan uang lagi?\n\n");
	printf("1. Masukkan uang lagi\n");
	printf("2. Tidak\n");
	switch(getch())
	{
		case '1' : system("cls");
			uang2();
				break;
		case '2' : system("cls");
			beli();
				break;
		default:printf("ERROR! Silahkan pilih kembali\n\n");
				nambah();
					break;
	}

}

// Fungsi Input Uang 2 (Nambah)
int uang2()
{
	printf("Pilih nominal uang yang ingin dimasukkan!\n\n");
	printf("1.  Rp 1,000.00\n");
	printf("2.  Rp 2,000.00\n");
	printf("3.  Rp 5,000.00\n");
	printf("4.  Rp 10,000.00\n");
	printf("5.  Rp 20,000.00\n");
	printf("6.  Rp 50,000.00\n");
	printf("7.  Rp 100,000.00\n");

	switch(getch())
	{
		case '1': jumlah1 = cash[0];
			beli();
				break;
		case '2': jumlah1 = cash[1];
			beli();
				break;
		case '3': jumlah1 = cash[2];
			beli();
				break;
		case '4': jumlah1 = cash[3];
			beli();
				break;
		case '5': jumlah1 = cash[4];
			beli();
				break;
		case '6': jumlah1 = cash[5];
			beli();
				break;
		case '7': jumlah1 = cash[6];
			beli();
				break;
		default: system("cls");
				printf("ERROR! Silahkan pilih kembali\n\n");
				uang2();
				break;
	}
}

// Transaksi
int beli()
{
	system("cls");
	total = jumlah1 + jumlah;
	listmenu();
	printf("Berapa minuman yang ingin dibeli?");
	scanf("%d",&tot);
	system("cls");
	printf("\n======================================================================================");
	printf("\n\n               Silahkan pilih minuman %d yang diinginkan.....\n\n",tot);
	printf("======================================================================================\n\n\n");
	listmenu();

	for(i=0; i<tot ;i++)
		{
		printf("Pilih No. Minuman yang diinginkan");
			scanf("%d",&num);

		dibeli[i] = Minuman[num];
		hargaminuman = hargaminuman + stock[num-1];
		}

	akhir();
}

// Display Perhitungan Bill dan Sorting Harga Kecil ke Besar
int akhir()
{
	sort(dibeli, tot);
	kembalian=total-hargaminuman;

	//sort dibeli[i]
	if (hargaminuman>total)
	{
		system("cls");
		printf("Daftar Minuman\n\n");
		printf("\n======================================================================================\n\n");
		printf("uang yang dimasukkan tidak cukup untuk melakukan transaksi! Silahkan mengulang atau batalkan transaksi. \n\n");
		printf("1. Ulang transaksi\n");
		printf("2. Keluar\n");

		switch(getch())
		{
			case '1': system("cls");
				uang1();
					break;
			case '2': system("cls");
				keluar();
					break;
		}
	}
	else
	system("cls");

		printf("\n\n\n\n");
		printf("                       Minuman anda sudah dapat diambil!\n\n");
		printf("                       Nominal uang yang anda masukkan = Rp %d\n",total);
		printf("                       Minuman yang dibeli :\n");
			for(i=0; i<tot; i++){
			printf("                       %s                       harga %s\n", dibeli[i].merk, dibeli[i].price);
		}
		printf("                       Harga Minuman yang dibeli       = Rp %d\n", hargaminuman);
		printf("                       Kembalian                       = Rp %d   \n\n\n\n\n\n",kembalian);
		printf("---------------------------------------------------------------------------------------\n\n");
		printf("                       Apakah Anda ingin melakukan transaksi lagi? \n\n");
		printf("---------------------------------------------------------------------------------------\n\n");
		printf("                       1. Ya\n");
		printf("                       2. Tidak");

		switch (getch())
		{
			case '1' : system ("cls");
						main();
						break;
			case '2' : system ("cls");
						keluar();
						break;
			default : system ("cls");
						printf("Error! Silahkan ketik '1' untuk melakukan transaksi atau '2' untuk berhenti");
						akhir();
						break;
		}
}

// Help Menu
int help()
{
printf("\n-------------------------------------------------------------\n");
		printf("\nCara membeli minuman di Vending Machine 1.0: \n");
		printf("\n1. Pilih menu 'Start' dengan mengetik '1' untuk membeli minuman.\n");
		printf("2. Akan tersedia minuman-minuman dingin beserta harga-harganya.\n");
		printf("3. Pilih minuman yang Anda ingin beli.\n");
		printf("4. Masukkan uang.\n");
		printf("5. Tunggu beberapa saat hingga minuman Anda keluar.\n");
		printf("6. Ambil kembaliannya jika Anda memasukkan uang lebih.\n");
		printf("7. Selamat menikmati!\n");

	printf("\n----------------------------------------------------------------------\n");
	printf("Apakah Anda ingin kembali ke menu utama?");
	printf("\n[Ketik '1' jika iya atau ketik '0' jika tidak]\n");

	switch(getch())
	{
		case '1': system("cls");
			main();
			break;
		case '0': system("cls");
			printf("Terima Kasih telah menggunakan Vending Machine 1.0! :)\n");
			return 0;
			break;
		default : system("cls");
			printf("ERROR!! Silahkan memilih dengan mengetik '1' untuk ke menu utama atau '0' untuk mengakhiri!");
			help();
			break;
	}
}
 
// Exit Program
int keluar()
{
	printf("Apakah anda ingin keluar dari Program ini?\n\n");
	printf("1. Keluar\n");
	printf("2. Menu Utama\n");

	switch(getch())
	{
		case '1': system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tTerima kasih telah menggunakan program ini!!\n\n\n\n\n\n\n\n\n\n\n\n");
						exit(0);
						break;
		case '2': system("cls");
					main();
						break;
		default : system("cls");
				printf("Error!! silahkan pilih lagi\n\n");
				 keluar();
				 break;
	}

}
