/**
**	Sigla: stddk
**	Carrega todos os cards do baralho padrao em uma struct do tipo Deck
**
*/

struct Deck {
	struct Card cards[24];
	int deck_size;
} STANDARD_DECK;

void stddk_load_standard_deck() {
	STANDARD_DECK.deck_size = 24;
	STANDARD_DECK.cards[ 0] = crd_make_card("Send virus", 85.00, 20.00, 3.0, 500, 60.00);
	STANDARD_DECK.cards[ 1] = crd_make_card("Update Firewalls", 10.00, 80.00, 1.5, 1000, 10.00);
	STANDARD_DECK.cards[ 2] = crd_make_card("Use Python", 60.00, 45.00, 3.5, 430, 49.00);
	STANDARD_DECK.cards[ 3] = crd_make_card("Use C", 65.00, 55.00, 2.1, 420, 50.00);
	STANDARD_DECK.cards[ 4] = crd_make_card("Use Ruby", 55.00, 43.00, 1.0, 650, 52.00);
	STANDARD_DECK.cards[ 5] = crd_make_card("Use VPN", 5.00, 85.00, 2.9, 400, 87.00);
	STANDARD_DECK.cards[ 6] = crd_make_card("Brute Force", 40.00, 25.00, 0.1, 850, 5.00);
	STANDARD_DECK.cards[ 7] = crd_make_card("Social Engineering", 90.00, 0.00, 0.4, 950, 85.00);
	STANDARD_DECK.cards[ 8] = crd_make_card("Aapagando Las Luces EMP", 30.00, 50.00, 5.0, 1000, 0.00);
	STANDARD_DECK.cards[ 9] = crd_make_card("Hack terminal", 63.00, 40.00, 2.0, 350, 70.00);
	STANDARD_DECK.cards[10] = crd_make_card("Hack server", 73.00, 30.00, 1.4, 550, 53.00);
	STANDARD_DECK.cards[11] = crd_make_card("Forced Shutdown", 0.00, 100.00, 0.1, 1000, 0.00);
	STANDARD_DECK.cards[12] = crd_make_card("Sintax Error", 0.00, 0.00, 0.1, 0, 0.00);
	STANDARD_DECK.cards[13] = crd_make_card("Seja o Escolhido", 100.00, 100.00, 5.0, 1000, 100.00);
	STANDARD_DECK.cards[14] = crd_make_card("SQL Injection", 45.00, 10.00, 3.2, 465, 60.00);
	STANDARD_DECK.cards[15] = crd_make_card("Defensive Maneuver", 20.00, 75.00, 3.1, 630, 20.00);
	STANDARD_DECK.cards[16] = crd_make_card("Coffee mug", 45.00, 40.00, 2.1, 300, 73.00);
	STANDARD_DECK.cards[17] = crd_make_card("Raise your...", 42.00, 30.00, 1.5, 250, 15.00);
	STANDARD_DECK.cards[18] = crd_make_card("Ataque de maquinas zumbis", 87.00, 80.00, 0.2, 750, 80.00);
	STANDARD_DECK.cards[19] = crd_make_card("Trojan", 58.00, 12.00, 2.6, 200, 33.00);
	STANDARD_DECK.cards[20] = crd_make_card("Use VR Set", 20.00, 35.00, 1.6, 100, 46.00);
	STANDARD_DECK.cards[21] = crd_make_card("Deep Web Attack", 66.00, 0.00, 3.2, 670, 95.00);
	STANDARD_DECK.cards[22] = crd_make_card("Blackmail", 82.00, 13.00, 2.2, 222, 100.00);
	STANDARD_DECK.cards[23] = crd_make_card("IP Tracins", 27.00, 78.00, 4.1, 780, 30.00);
}
