#include <iostream>
#include "User.h"
#include "MailBox.h"

int main()
{
	
	/*W funkcji main() utworzyæ  skrzynke : mbox  oraz 4 u¿ytkowników A, B, C i D.

		Utworzyæ rózne scenariusze wysy³ania wiadomoœci np :

	A wysyla wiadomoœæ do B, C i D;

	B wysyla wiadomoœæ do A, C i D;

	C odczytuje wiadomoœæ itd.*/

	
	MailBox mbox("log.txt", "backup.txt");
	User A(&mbox,"A");
	User B(&mbox,"B");
	User C(&mbox,"C");
	User D(&mbox,"D");

	A.send("no hej1",A);
	A.send("no hej2",B);
	A.send("no hej3",C);
	A.send("no hej4",D);

	B.send("siema1", A);
	B.send("siema2", B);
	B.send("siema3", C);
	B.send("siema4", D);

	C.send("yo1", A);
	C.send("yo2", B);
	C.send("yo3", C);
	C.send("yo4", D);


	mbox.print();
	

	return 0;
}