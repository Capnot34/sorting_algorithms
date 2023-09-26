#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * card_value - Get the value of a card.
 * @value: The card's string value.
 * Return: The card's integer value.
 */
int card_value(const char *value)
{
	int i;
	char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
	};

	for (i = 0; i < 13; i++)
	{
		if (!strcmp(values[i], value))
			return (i);
	}
	return (-1);
}

/**
 * compare_cards - Compare two cards.
 * @a: First card.
 * @b: Second card.
 * Return: Positive if a > b, negative if a < b, and zero if equal.
 */
int compare_cards(const void *a, const void *b)
{
	deck_node_t *card_a = *(deck_node_t **)a;
	deck_node_t *card_b = *(deck_node_t **)b;
	int value_diff = card_value(card_a->card->value) - card_value
		(card_b->card->value);

	if (card_a->card->kind != card_b->card->kind)
		return (card_a->card->kind - card_b->card->kind);

	return (value_diff);
}

/**
 * sort_deck - Sort a deck of cards.
 * @deck: A pointer to the deck.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t **array, *current;
	size_t i, count = 0;

	for (current = *deck; current; current = current->next
			count++;

			array = malloc(sizeof(deck_node_t *) * count);
			if (!array)
			return;

			for (i = 0, current = *deck; i < count; i++, current = current->next)
			array[i] = current;

			qsort(array, count, sizeof(deck_node_t *), compare_cards);

			for (i = 0; i < count - 1; i++)
			{

			array[i]->next = array[i + 1];

			array[i + 1]->prev = array[i];
			}

			array[0]->prev = NULL;

			array[count - 1]->next = NULL;

			*deck = array[0];

			free(array);
}
