//Assignment-2 DS Theory Addition & Multiplication of Polynomial Using Linked List by Aayush Patel 2K20/CO/11
#include <stdio.h>
#include <stdlib.h>
struct poly
{
	float coef;
	int expo;
	struct poly *nxt;
};
void input(struct poly **s)
{
	struct poly *p, *q;
	int sz;
	printf("Enter size of polynomial:");
	scanf("%d", &sz);
	printf("Enter Polynomial(Degree-Coeffcient):\n");
	for (int i = 0; i < sz; i++)
	{
		p = (struct poly *)malloc(sizeof(struct poly));
		p->nxt = NULL;
		scanf("%d", &(p->expo));
		scanf("%f", &(p->coef));
		if (*s == NULL)
			*s = p;
		else
		{
			q = *s;
			while (q->nxt != NULL)
			{
				q = q->nxt;
			}
			q->nxt = p;
		}
	}
}
void print(struct poly *s)
{
	struct poly *p;
	p = s;
	if (p == NULL)
		return;
	while (p != NULL)
	{
		if (p->nxt == NULL)
			printf("(%.1f)x^%d", p->coef, p->expo);
		else
			printf("(%.1f)x^%d+", p->coef, p->expo);
		p = p->nxt;
	}
}

struct poly *polyadd(struct poly *p1, struct poly *p2) //polynomial addition function
{
	struct poly *p3 = NULL, *p, *q;
	if (p1 == NULL)
	{
		p3 = p2;
		return p3;
	}
	else if (p2 == NULL)
	{
		p3 = p1;
		return p3;
	}
	while (p1 != NULL || p2 != NULL)
	{
		p = (struct poly *)malloc(sizeof(struct poly));
		p->nxt = NULL;
		if (p1 != NULL && p2 != NULL)
		{
			if (p1->expo == p2->expo)
			{
				p->coef = p1->coef + p2->coef;
				p->expo = p1->expo;
				p1 = p1->nxt;
				p2 = p2->nxt;
			}
			else if (p1->expo > p2->expo)
			{
				p->coef = p1->coef;
				p->expo = p1->expo;
				p1 = p1->nxt;
			}
			else
			{
				p->coef = p2->coef;
				p->expo = p2->expo;
				p2 = p2->nxt;
			}
		}
		else
		{
			if (p2 == NULL)
			{
				p->coef = p1->coef;
				p->expo = p1->expo;
				p1 = p1->nxt;
			}
			else if (p1 == NULL)
			{
				p->coef = p2->coef;
				p->expo = p2->expo;
				p2 = p2->nxt;
			}
		}
		if (p3 == NULL)
			p3 = p;
		else
		{
			q = p3;
			while (q->nxt != NULL)
			{
				q = q->nxt;
			}
			q->nxt = p;
		}
	}
	return (p3);
}
struct poly *polymult(struct poly *p1, struct poly *p2)
{
	struct poly *p3 = NULL, *p, *q, *l = NULL, *m;
	while (p1 != NULL)
	{
		p = p2;
		l = NULL;
		while (p != NULL)
		{
			q = (struct poly *)malloc(sizeof(struct poly));
			q->coef = p1->coef * p->coef;
			q->expo = p1->expo + p->expo;
			q->nxt = NULL;
			if (l == NULL)
			{
				l = q;
			}
			else
			{
				m = l;
				while (m->nxt != NULL)
				{
					m = m->nxt;
				}
				m->nxt = q;
			}
			p = p->nxt;
		}
		p3 = polyadd(p3,l);
		p1 = p1->nxt;
	}
	return (p3);
}
main()
{
	//printf("DS LAB Practical-16 Polynomial Addition and Multiplication using Linked List by Aayush Patel 2K20/CO/11\n");
	struct poly *p1 = NULL, *p2 = NULL;
	printf("First Polynomial(p1):\n");
	input(&p1);
	printf("Second Polynomial(p2):\n");
	input(&p2);
	printf("\nAddition of 2 Polynomials p1 & p2:");
	print(p1);
	printf("\t + \t");
	print(p2);
	printf("\n = \t");
	print(polyadd(p1, p2));
	printf("\n\nMultiplication of 2 Polynomials p1 & p2:");
	print(p1);
	printf("\t * \t");
	print(p2);
	printf("\n = \t");
	print(polymult(p1, p2));
}
