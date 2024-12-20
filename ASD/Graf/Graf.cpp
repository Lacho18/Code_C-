#include <iostream>

const int numberOfEdged = 5;

struct Graf {
	char vruh;
	Graf* next;
} *Starts[5];

//Функции за помощтна опашка, използвана при обхождането на графа по широчина --------------------------------------------
struct Opashka {
	char value;
	Opashka* next;
} *first, * last;

void Inicialization() {
	first = nullptr;
	last = nullptr;
}

void AddToOpashka(char key) {
	if (first == nullptr) {
		first = new Opashka;
		first->value = key;
		last = first;
		first->next = nullptr;
		last->next = nullptr;
	}
	else {
		Opashka* p = new Opashka;
		p->value = key;
		p->next = nullptr;
		last->next = p;
		last = p;
	}
}

bool EmptyOpashka() {
	if (first == nullptr) {
		return true;
	}
	else return false;
}

char DeleteOtOpashka() {
	Opashka* p = first;
	char z = p->value;
	first = first->next;
	delete p;
	return z;
}
//----------------------------------------------------------------------------------------------------------

void InicialiceGraf(Graf* vurhove[]) {
	for (int i = 0; i < numberOfEdged; i++) {
		vurhove[i] = nullptr;
	}
}

bool SearchVruh(Graf* vurhove[], char vruh) {
	int i = 0;
	while (vurhove[i] != nullptr && i < numberOfEdged) {
		if (vurhove[i]->vruh == vruh) {
			return true;
		}
		i++;
	}
	return false;
}

bool SearchRebro(Graf* vurhove[], char vruh1, char vruh2) {
	int i = 0;

	if (SearchVruh(vurhove, vruh1) && SearchVruh(vurhove, vruh2)) {
		while (vurhove[i] != nullptr && i < numberOfEdged) {
			if (vurhove[i]->vruh == vruh1) {
				break;
			}
			i++;
		}

		Graf* p = vurhove[i];

		while (p->vruh != vruh2 && p->next != nullptr) {
			p = p->next;
		}

		if (p->vruh == vruh2) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		std::cout << "No such Edges" << std::endl;
		return false;
	}
}

void AddVruhToGraf(Graf* vurhove[], char vruh) {
	int i = 0;
	if (!SearchVruh(vurhove, vruh)) {
		while (vurhove[i] != nullptr && i < numberOfEdged) {
			i++;
		}
		vurhove[i] = new Graf;
		vurhove[i]->vruh = vruh;
		vurhove[i]->next = nullptr;
	}
	else {
		std::cout << "Tozi vruh veche sushtestvyva!" << std::endl;
	}
}

void AddRebroToGraf(Graf* vurhove[], char vruh1, char vruh2) {
	int i = 0;
	if (!SearchRebro(vurhove, vruh1, vruh2)) {
		if (!SearchVruh(vurhove, vruh1)) {
			AddVruhToGraf(vurhove, vruh1);
		}
		if (!SearchVruh(vurhove, vruh2)) {
			AddVruhToGraf(vurhove, vruh2);
		}

		while (vurhove[i]->vruh != vruh1)  i++;

		Graf* p = vurhove[i];

		while (p->next) p = p->next;

		Graf* q = new Graf;
		q->vruh = vruh2;
		q->next = nullptr;
		p->next = q;
	}
	else {
		std::cout << "Rebroto veche sushtestvuva!" << std::endl;
	}
}

void DeleteVruh(Graf* vurhove[], char vruh) {
	if (SearchVruh(vurhove, vruh)) {
		int i = 0;
		while (vurhove[i]->vruh != vruh) i++;

		Graf* p = vurhove[i]->next;
		Graf* q = vurhove[i]->next;

		delete vurhove[i];
		vurhove[i] = new Graf;
		vurhove[i]->vruh = vurhove[i + 1]->vruh;
		vurhove[i]->next = vurhove[i + 1]->next;

		for (int j = i + 1; j < numberOfEdged; j++) {
			if (vurhove[j + 1]) {
				vurhove[j] = vurhove[j + 1];
				vurhove[j]->vruh = vurhove[j + 1]->vruh;
				vurhove[j]->next = vurhove[j + 1]->next;
			}
			else {
				delete vurhove[j];
				vurhove[j] = nullptr;
			}
		}

		if (p) {
			while (p) {
				q = p;
				p = p->next;
				delete q;
			}
		}

		for (int j = 0; j < numberOfEdged; j++) {
			if (vurhove[j] != nullptr) {
				Graf* h = vurhove[j]->next;
				Graf* k = vurhove[j];

				while (h) {
					if (h->vruh == vruh) {
						k->next = h->next;
						delete h;
						h = k->next;
					}
					else {
						h = h->next;
					}
				}
			}
		}
	}
	else {
		std::cout << "Nqma takuv vruh" << std::endl;
	}
}

void DeleteRebro(Graf* vurhove[], char vruh1, char vruh2) {
	if (SearchRebro(vurhove, vruh1, vruh2)) {
		int i = 0;

		while (vurhove[i]->vruh != vruh1) i++;

		Graf* p = vurhove[i];
		Graf* q = vurhove[i];
		while (p->vruh != vruh2) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
	}
	else {
		std::cout << "Nqma takova rebro!" << std::endl;
	}
}

int IndexOfVruh(Graf* vurhove[], char vruh) {
	int i = 0;

	while (vurhove[i]->vruh != vruh) i++;

	return i;
}

void ObhojdanePoShirochina(Graf* vurhove[], char NachalenVruh) {
	int mas[5] = {};

	for (int i = 0; i < numberOfEdged; i++) mas[i] = 0;

	Inicialization();
	AddToOpashka(NachalenVruh);
	while (!EmptyOpashka()) {
		char s = DeleteOtOpashka();
		int j = IndexOfVruh(vurhove, s);

		if (mas[j] == 0) {
			mas[j] = 1;
			std::cout << s << " ";

			for (Graf* t = vurhove[j]; t != nullptr; t = t->next) {
				int h = IndexOfVruh(vurhove, t->vruh);
				if (mas[h] == 0)
					AddToOpashka(t->vruh);
			}
		}
	}

}

void ObhojdanePoDuvlbochina(Graf* vurhove[], char NachalenVruh, int mas[]) {
	std::cout << NachalenVruh << " ";
	int i = 0;

	i = IndexOfVruh(vurhove, NachalenVruh);

	mas[i] = 1;

	for (Graf* t = vurhove[i]; t != nullptr; t = t->next) {
		int h = IndexOfVruh(vurhove, t->vruh);
		if (mas[h] == 0) {
			ObhojdanePoDuvlbochina(vurhove, t->vruh, mas);
		}
	}
}



int main()
{
	InicialiceGraf(Starts);
	/*AddVruhToGraf(Starts, 'A');
	AddVruhToGraf(Starts, 'B');
	AddVruhToGraf(Starts, 'C');
	AddVruhToGraf(Starts, 'D');
	AddVruhToGraf(Starts, 'E');
	AddRebroToGraf(Starts, 'A', 'B');
	AddRebroToGraf(Starts, 'A', 'D');
	AddRebroToGraf(Starts, 'A', 'C');
	AddRebroToGraf(Starts, 'B', 'D');
	AddRebroToGraf(Starts, 'B', 'E');
	AddRebroToGraf(Starts, 'C', 'D');
	AddRebroToGraf(Starts, 'E', 'A');*/

	AddVruhToGraf(Starts, 'A');
	AddVruhToGraf(Starts, 'B');
	AddVruhToGraf(Starts, 'C');
	AddVruhToGraf(Starts, 'D');
	AddVruhToGraf(Starts, 'E');
	AddRebroToGraf(Starts, 'A', 'B');
	AddRebroToGraf(Starts, 'A', 'C');
	AddRebroToGraf(Starts, 'B', 'D');
	AddRebroToGraf(Starts, 'B', 'E');
	AddRebroToGraf(Starts, 'E', 'C');

	int masiv[5] = {};
	DeleteVruh(Starts, 'D');
	ObhojdanePoDuvlbochina(Starts, 'A', masiv);
	std::cout << "   " << std::endl;
	std::cout << "   " << std::endl;
	std::cout << "   " << std::endl;
	std::cout << "   " << std::endl;
	std::cout << SearchRebro(Starts, 'A', 'B');
}
