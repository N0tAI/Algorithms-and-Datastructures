#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int coeff;
	int exp;
} Term;
typedef struct
{
	int n;
	Term* terms;
} Polynomial;

void create(Polynomial* p)
{
	int i;
	printf("Number of terms?");
	scanf("%d", &p->n);
	p->terms = (struct Term*)malloc(p->n * sizeof(Term));

	printf("Enter terms\n");
	for (i = 0; i < p->n; i++)
		scanf("%d%d", &p->terms[i].coeff, &p -> terms[i].exp);

}
void display(Polynomial p)
{
	int i;
	for (i = 0; i < p.n; i++)

		printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp);
	printf("\n");
}

Polynomial* add(Polynomial* p1, Polynomial* p2)
{
	int i, j, k;
	Polynomial* sum;

	sum = (Polynomial*)malloc(sizeof(Polynomial));
	sum->terms = (struct Term*)malloc((p1->n + p2 -
	> n) * sizeof(struct Term));
	i = j = k = 0;

	while (i < p1->n && j < p2->n)
	{
		if (p1->terms[i].exp > p2->terms[j].exp)
			sum->terms[k++] = p1->terms[i++];
		else if (p1->terms[i].exp < p2->terms[j].exp)
			sum->terms[k++] = p2->terms[j++];
		else
		{
			sum->terms[k].exp = p1->terms[i].exp;
			sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
		}
	}
	for (; i < p1->n; i++)sum->terms[k++] = p1->terms[i];
	for (; j < p2->n; j++)sum->terms[k++] = p2->terms[j];

	sum->n = k;
	return sum;
}