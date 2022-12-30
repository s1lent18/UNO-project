#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

char bundle[54][10] = {"R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "G0", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "B0", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "Y0", "Y1", "Y2", "Y3", "Y4", "Y5", "Y6", "Y7", "Y8", "Y9", "BR", "BS", "RS", "RR", "YS", "YR", "GS", "GR", "Y+2", "B+2", "G+2", "R+2", "D4", "W"};

int num = 0; // for holding the randomly generating value

int h = -1; // our counter for the do while loop

char player1[27][5]; // cards for player1 are stored here

char player2[27][5]; // cards for player 2 are stored here

char assigned[54][10]; // a string array for storing the assigned cards for either player

int assign = 0; // for counting the number of cards assigned by now

char input[5]; // the input of any user

char currentcard[5]; // last card any player threw

int pos = 0; // for storing the current position of the card

int count = 0; // for checking how many times the loop has executed

int a = 0, d = 0;

int skipcount1 = 0, skipcount2 = 0; 

char color[2]; // storing the color of the choice of either player when Draw 4 or Wild is entered

int count1 = 0, count2 = 0; // count1 and 2 will have the current number of cards in a deck of each respective player

int compare = 0;

void card_distribution_for_player1()
{
	srand(time(0));
	
	// since the first card will always be unique thats why it doesn't need to be checked
	
	num = rand() % 54;
	
	strcpy(assigned[assign], bundle[num]);
	
	strcpy(player1[a], bundle[num]);
	
	count1++;
	
	for(a = 1; a < 7; a++)
	{
		deckforP1:
			
			num = rand() % 54;
						
			for(int z = 0; z < 54; z++)
			{
				if(strcmp(assigned[z], bundle[num]) == 0)
				{
					goto deckforP1;
				}
			}
			
		assign++;
		
		strcpy(assigned[assign], bundle[num]);
		
		strcpy(player1[a], bundle[num]);
			
		count1++;	
	}
	// printing of cards for player 1
	
	printf("Deck For Player 1: \n");
	
	for(int b = 0; b < 7; b++)
	{
		printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);	
	}
	
	printf("\n\n");
}

void card_distribution_for_player2()
{
	// card distribution
	
	for(d = 0; d < 7; d++)
	{
		deckforP2:
		
		num = rand() % 54;
		
		// checking if the generated card is unique
		
		for(int z = 0; z < 54; z++)
		{
			if(strcmp(assigned[z], bundle[num]) == 0)
			{
				goto deckforP2;
			}
		}
		
		assign++;
		
		strcpy(assigned[assign], bundle[num]);
		
		strcpy(player2[d], bundle[num]);
		
		count2++;
		
	}
		// printing the cards for player 2
	
		printf("The deck for Player 2: \n");
	
		for(int b = 0; b < 7; b++)
		{
			printf("Card %d for player 2 is: %s\n", (b + 1), player2[b]);
		}

}

void firstcard()
{
	// using rand search till 40 so avoid Skip, Reverse, Draw 2, Draw 4 and Wild card 
	
	first:
	
		num = rand() % 40;
	
		for(int b = 0; b < 54; b++)
		{
			
			if(strcmp(assigned[b], bundle[num]) == 0)
			{
				goto first;
			}
		}
		
		assign++;
		
		strcpy(assigned[assign], bundle[num]);
		
		strcpy(currentcard, bundle[num]);
		
		printf("\n\n---------------- First Card is %s ----------------", currentcard);
		
}

int main()
{
	printf("---------------- Welcome To UNO ----------------\n");
	
	printf("Rules:\n1.Each Player will be distributed 7 cards\n\n2.Player 1 will get the first turn.\n\n3.Each player have to throw the card according to either the color or the number of the last card if you dont have the  specific card you have to type (SKIP)\n\n4.After you entered SKIP a new card will be drawn and automatically will be added to your deck\n\n5.when only 1 card will be left for either of the players you will have to enter UNO just before playing the last card\n\n6.If you dont enter UNO before entering your last card, it wont be allowed to play and a new card will be added to your deck as a punishment\n\n\n\n---------------- Have Fun ----------------\n\n\n\n");
	
	card_distribution_for_player1();
	
	card_distribution_for_player2();
	
	firstcard();
	
	while(1)
	{
		skipcount2 = 0;
		
		pos = 0;
	
		inputforplayer1:

			h = -1;

			if(count1 == 1)
			{
				printf("\nPlayer 1, \nEnter Your Card: \n");

				strcpy(input, "\0");
			
				gets(input);
				
				if(strcmp(input, "SKIP") == 0)
				{
					skipcount1 = 1;
					
					goto skipcondition;
				}
				
				if(strcmp(input, "UNO") == 0)
				{
					printf("UNO activated");
					
					printf("\nPlayer 1, \nEnter Your Card: \n");

					strcpy(input, "\0");
			
					gets(input);
					
					goto check1;
					
				} else
				{
					unocondition:
					
					num = rand() % 54;
						
					for(int h = 0; h < 54; h++)
					{
						if(strcmp(assigned[h], bundle[num]) == 0)
						{
							goto unocondition;
						}
					}
					
					assign++;
				
					strcpy(assigned[assign], bundle[num]);
					
					strcpy(player1[count1], bundle[num]);
				
					count1++;
				
					for(int b = 0; b < 27; b++)
					{
						if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
						{
							printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
					
						} else
						{
							continue;
						}
					}
					
					goto check1;
				}
			} else
			{
				printf("\nPlayer 1, \nEnter Your Card: \n");

				strcpy(input, "\0");
			
				gets(input);
				
			}
			check1:
			do
			{
				if(skipcount1 == 0)
				{
					if(strcmp(input, "SKIP") == 0)
					{
						skipcount1 = 1;
						
						skipcondition:
							
							num = rand() % 54;
						
							for(int h = 0; h < 54; h++)
							{
								if(strcmp(assigned[h], bundle[num]) == 0)
								{
									goto skipcondition;
								}
							}
							
							assign++;
						
							strcpy(assigned[assign], bundle[num]);
							
							strcpy(player1[count1], bundle[num]);
						
							count1++;
						
							for(int b = 0; b < 27; b++)
							{
								if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
								{
									printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
							
								} else
								{
									continue;
								}
							}
							
							goto inputforplayer1;		
					}
				} else if (skipcount1 != 0 && (strcmp(input, "SKIP") == 0))
				{
					skipcount1 = 0;
		
					goto inputforplayer2;
		
				}
				if(strcmp(currentcard, "D4") == 0)
				{
					if(strncmp(input, color, 1) != 0)
					{
						goto inputforplayer1;
					}
				}
					
				if(h < 27)
				{
					h++;
					
				} else
				{
					goto inputforplayer1;
				}
				
				compare = strcmp(input, player1[h]);
						
			}while(compare != 0);
					
			checkforplayer1:
				
				if(strcmp(input, "W") == 0)
				{
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player1[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player1[pos], "\0");
					
					for(int i=pos;i<count1;i++)
    				{
        				strcpy(player1[i], player1[(i + 1) % count1]);
        
    				}
					
					strcpy(player1[count1-1], "\0");
					
					count1--;
					
					printf("What Color you want to continue with: R, B, Y, G\n");
					
					gets(color);
					
					for(int b = 0; b < 27; b++)
					{
						if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
						{
							printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
							
						} else
						{
							continue;
						}
					}
					
					strcpy(currentcard, color);
					
					printf("\n\n---------------- currentcard will be %s ----------------", currentcard);
					
				} else if (strcmp(input, "D4") == 0)
				{
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player1[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player1[pos], "\0");
					
					for(int i=pos;i<count1;i++)
    				{
        				strcpy(player1[i], player1[(i + 1) % count1]);
        
    				}
					
					strcpy(player1[count1-1], "\0");
					
					count1--;
					
					printf("What Color you want to continue with: R, B, Y, G\n");
					
					gets(color);
					
					for(int i = 0; i < 4; i++)
					{
						Draw4forplayer1:
							
							num = rand() % 54;
						
							for(int h = 0; h < 54; h++)
							{
								if(strcmp(assigned[h], bundle[num]) == 0)
								{
									goto Draw4forplayer1;
								}
							}
							
							assign++;
						
							strcpy(assigned[assign], bundle[num]);
						
							strcpy(player2[count2], bundle[num]);
						
							count2++;
						
							strcpy(currentcard, "D4");	
					}
							
					for(int b = 0, p = 0; b < 27; b++)
					{
						if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
						{
							printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
							
						} else
						{
							continue;
						}
					}
					
					printf("\n\n---------------- currentcard will be %s and the next color is %s----------------\n\n", currentcard, color);
					
					for(int b = 0; b < 27; b++)
					{
						if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
						{
							printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
							
						} else
						{
							continue;
						}
					}
					if(count1 == 0)
					{
						break;
					}
					
					goto inputforplayer1;
					
						
				} else if(((input[1] == 'R') || (input[1] == 'S')) && ((input[0] == currentcard[0]) || ((currentcard[1] == 'R') || (currentcard[1] == 'S')))) 
				{
					if(skipcount1 == 1)
					{
						skipcount1 = 0;
					}
					
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player1[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player1[pos], "\0");

					// pushing the whole array after position of the current card to the left for not leaving behind the gap
					
					for(int i=pos;i<count1;i++)
    				{
        				strcpy(player1[i], player1[(i + 1) % count1]);
        
    				}
					
					strcpy(player1[count1-1], "\0");
					
					count1--;
					
					for(int b = 0; b < 27; b++)
					{
						if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
						{
							printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
							
						} else
						{
							continue;
						}
					}
					
					strcpy(currentcard, input);
					
					printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
				
					if(count1 == 0)
					{
						break;
					}
						
					goto inputforplayer1;
					
				} else if (((strncmp(input, currentcard, 1) == 0) || (strcmp(currentcard, "D4") == 0)) && (input[1] != 'R') && (input[1] != 'S'))
				{
					if((strcmp(input, "R+2") == 0) || (strcmp(input, "B+2") == 0)  || (strcmp(input, "Y+2") == 0) || (strcmp(input, "G+2") == 0))
					{
						if(skipcount1 == 1)
						{
							skipcount1 = 0;
						}
						
						for(int i = 0; i < 27; i++)
						{
							if(strcmp(input, player1[i]) == 0)
							{
								pos = i;
								
							}
						}
					
						strcpy(player1[pos], "\0");
						
						for(int i=pos;i<count1;i++)
	    				{
	        				strcpy(player1[i], player1[(i + 1) % count1]);
	        
	    				}
						
						strcpy(player1[count1-1], "\0");
						
						count1--;
						
						for(int u = 0; u < 2; u++)
						{
							Draw2forplayer1:
								
								num = rand() % 54;
								
								for(int h = 0; h < 54; h++)
								{
									if(strcmp(assigned[h], bundle[num]) == 0)
									{
										goto Draw2forplayer1;
									}
								}
								
							assign++;
							
							strcpy(assigned[assign], bundle[num]);
							
							strcpy(player2[count2], bundle[num]);
							
							count2++;
		
						}
												
							strcpy(currentcard, input);
							
							for(int b = 0, p = 0; b < 27; b++)
							{
								if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
								{
									printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
							
								} else
								{
									continue;
								}
							}
						
							printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
						
							for(int b = 0; b < 27; b++)
							{
								if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
								{
									printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
								
								} else
								{
									continue;
								}
							}
					
							if(count1 == 0)
							{
								break;
							}
							
						goto inputforplayer1;
						
					} else if(strcmp(currentcard, "D4") == 0) 
					{
							for(int i = 0; i < 27; i++)
						{
							if(strcmp(input, player1[i]) == 0)
							{
								pos = i;
							}
						}
						
						strcpy(player1[pos], "\0");
						
						for(int i=pos;i<count1;i++)
	    				{
	        				strcpy(player1[i], player1[(i + 1) % count1]);
	        
	    				}
						
						strcpy(player1[count1-1], "\0");
						
						count1--;
						
						for(int b = 0; b < 27; b++)
						{
							if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
							{
								printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
								
							} else
							{
								continue;
							}
						}
						
						strcpy(currentcard, input);
						
						printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
						
					} else
					{
						for(int i = 0; i < 27; i++)
						{
							if(strcmp(input, player1[i]) == 0)
							{
								pos = i;
							}
						}
						
						strcpy(player1[pos], "\0");
						
						for(int i=pos;i<count1;i++)
	    				{
	        				strcpy(player1[i], player1[(i + 1) % count1]);
	        
	    				}
						
						strcpy(player1[count1-1], "\0");
						
						count1--;
						
						for(int b = 0; b < 27; b++)
						{
							if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
							{
								printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
								
							} else
							{
								continue;
							}
						}
						
						strcpy(currentcard, input);
						
						printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
					}
				} else if ((input[1] == currentcard[1]))
				{
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player1[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player1[pos], "\0");
					
					for(int i=pos;i<count1;i++)
    				{
        				strcpy(player1[i], player1[(i + 1) % count1]);
        
    				}
					
					strcpy(player1[count1-1], "\0");
					
					count1--;
					
					for(int b = 0; b < 27; b++)
					{
						if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
						{
							printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
							
						} else
						{
							continue;
						}
					}
					
					strcpy(currentcard, input);
					
					printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
					
				} else
				{
					goto inputforplayer1;
				}
				
				if(count1 == 0)
				{
					break;
				}
				
		skipcount1 = 0;
				
		pos = 0;
	
		inputforplayer2:
			
			h = -1;

			if(count2 == 1)
			{
				printf("\nPlayer 2, \nEnter Your Card: \n");

				strcpy(input, "\0");
			
				gets(input);
				
				if(strcmp(input, "SKIP") == 0)
				{
					skipcount2 = 1;
					
					goto skipcondition2;
				}
				
				if(strcmp(input, "UNO") == 0)
				{
					
					printf("UNO activated\n");
					
					printf("\nPlayer 2, \nEnter Your Card: \n");

					strcpy(input, "\0");
			
					gets(input);
					
					goto check2;
					
				} else
				{
					unocondition2:
					
					num = rand() % 54;
						
					for(int h = 0; h < 54; h++)
					{
						if(strcmp(assigned[h], bundle[num]) == 0)
						{
							goto unocondition;
						}
					}
					
					assign++;
				
					strcpy(assigned[assign], bundle[num]);
					
					strcpy(player2[count2], bundle[num]);
				
					count2++;
				
					for(int b = 0; b < 27; b++)
					{
						if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
						{
							printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
					
						} else
						{
							continue;
						}
					}
					
					goto check2;
				}
			} else
			{
				printf("\nPlayer 2, \nEnter Your Card: \n");

				strcpy(input, "\0");
			
				gets(input);
				
			}
			check2:	
			do
			{
				if(skipcount2 == 0)
				{
						if(strcmp(input, "SKIP") == 0)
						{
							skipcount2 = 1;
						
							skipcondition2:
							
							num = rand() % 54;
						
							for(int h = 0; h < 54; h++)
							{
								if(strcmp(assigned[h], bundle[num]) == 0)
								{
									goto skipcondition2;
								}
							}
							
							assign++;
						
							strcpy(assigned[assign], bundle[num]);
						
							strcpy(player2[count2], bundle[num]);
						
							count2++;
						
							for(int b = 0; b < 27; b++)
							{
								if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
								{
									printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
							
								} else
								{
									continue;
								}
							}
							
							goto inputforplayer2;		
					
						}
				} else if (skipcount2 != 0  && (strcmp(input, "SKIP") == 0))
				{
					skipcount2 = 0;
					
					goto inputforplayer1;
		
				}
				if(strcmp(currentcard, "D4") == 0)
				{
					if(strncmp(input, color, 1) != 0)
					{
						goto inputforplayer2;
						
					} 
				}
					
				if(h < 27)
				{
					h++;
					
				} else
				{
					goto inputforplayer2;
				}
				
				compare = strcmp(input, player2[h]);
						
			}while(compare != 0);
			
			checkforplayer2:
				
				if(strcmp(input, "W") == 0)
				{
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player2[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player2[pos], "\0");
					
					for(int i=pos;i < count2;i++)
    				{
        				strcpy(player2[i], player2[(i + 1) % count2]);
        
    				}
					
					strcpy(player2[count2-1], "\0");
					
					count2--;

					printf("What Color you want to continue with: R, B, Y, G\n");
					
					gets(color);
					
					strcpy(currentcard, color);
					
					printf("\n\n---------------- currentcard will be %s ----------------", currentcard);
					
				} else if (strcmp(input, "D4") == 0)
				{
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player2[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player2[pos], "\0");
					
					for(int i=pos;i < count2;i++)
    				{
        				strcpy(player2[i], player2[(i + 1) % count2]);
        
    				}
					
					strcpy(player2[count2-1], "\0");
					
					count2--;
	
					printf("What Color you want to continue with: R, B, Y, G\n");
					
					gets(color);
					
					for(int i = 0; i < 4; i++)
					{
						Draw4forplayer2:
							
							num = rand() % 54;
						
							for(int h = 0; h < 54; h++)
							{
								if(strcmp(assigned[h], bundle[num]) == 0)
								{
									goto Draw4forplayer2;
								}
							}
							
							assign++;
						
							strcpy(assigned[assign], bundle[num]);
						
							strcpy(player1[count1], bundle[num]);
						
							count1++;
						
							strcpy(currentcard, "D4");	
					}
					
					for(int b = 0, p = 0; b < 27; b++)
					{
						if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
						{
							printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
							
						} else
						{
							continue;
						}
					}
					
					printf("\n\n---------------- currentcard will be %s and the next color is %s----------------\n\n", currentcard, color);
					
					for(int b = 0; b < 27; b++)
					{
						if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
						{
							printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
							
						} else
						{
							continue;
						}
					}
					if(count2 == 0)
					{
						break;
					}
					
					goto inputforplayer2;
					
					
				} else if(((input[1] == 'R') || (input[1] == 'S')) && ((input[0] == currentcard[0]) || ((currentcard[1] == 'R') || (currentcard[1] == 'S'))))
				{
					if(skipcount2 == 1)
					{
						skipcount2 = 0;
					}
					
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player2[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player2[pos], "\0");
					
					for(int i=pos; i < count2;i++)
    				{
        				strcpy(player2[i], player2[(i + 1) % count2]);
        
    				}
					
					strcpy(player2[count2-1], "\0");
					
					count2--;

					for(int b = 0; b < 27; b++)
					{
						if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
						{
							printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
							
						} else
						{
							continue;
						}
					}
					
					strcpy(currentcard, input);
					
					printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
					
					if(count2 == 0)
					{
						break;
					}
						
					goto inputforplayer2;
					
				} else if (((strncmp(input, currentcard, 1) == 0) || (strcmp(currentcard, "D4") == 0)) && ((input[1] != 'R') && (input[1] != 'S')))
				{
					 if((strcmp(input, "R+2") == 0) || (strcmp(input, "B+2") == 0)  || (strcmp(input, "Y+2") == 0) || (strcmp(input, "G+2") == 0))
					{
						
						if(skipcount2 == 1)
						{
							skipcount2 = 0;
						}
							
						for(int i = 0; i < 27; i++)
						{
							if(strcmp(input, player2[i]) == 0)
							{
								pos = i;
							}
						}
					
						strcpy(player2[pos], "\0");
						
						for(int i=pos;i<count2;i++)
	    				{
	        				strcpy(player2[i], player2[(i + 1) % count2]);
	        
	    				}
						
						strcpy(player2[count2-1], "\0");
						
						count2--;
	
						for(int u = 0; u < 2; u++)
						{
							Draw2forplayer2:
								
								num = rand() % 54;
								
								for(int h = 0; h < 54; h++)
								{
									if(strcmp(assigned[h], bundle[num]) == 0)
									{
										goto Draw2forplayer2;
									}
								}
								
							assign++;
							
							strcpy(assigned[assign], bundle[num]);
							
							strcpy(player1[count1], bundle[num]);
							
							count1++;
		
						}
												
							strcpy(currentcard, input);
							
							for(int b = 0, p = 0; b < 27; b++)
							{
								if(player1[b][0] >= 'A' && player1[b][0] <= 'Z')
								{
									printf("Card %d for Player 1 is: %s\n", (b + 1), player1[b]);
								
								} else
								{
									continue;
								}
							}
						
							printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
						
							for(int b = 0; b < 27; b++)
							{
								if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
								{
									printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
								
								} else
								{
									continue;
								}
							}
							
							if(count2 == 0)
							{	
								break;
							}
							
						goto inputforplayer2;
					
				} else if (strcmp(currentcard, "D4") == 0)
				{
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player2[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player2[pos], "\0");
					
					for(int i=pos;i<count2;i++)
    				{
        				strcpy(player2[i], player2[(i + 1) % count2]);
        
    				}
    				
					strcpy(player2[count2-1], "\0");
					
					count2--;
	
					for(int b = 0; b < 27; b++)
					{
						if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
						{
							printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
							
						} else
						{
							continue;
						}
					}
					
					strcpy(currentcard, input);
					
					printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
					
				} else 
				{
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player2[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player2[pos], "\0");
					
					for(int i=pos;i<count2;i++)
    				{
        				strcpy(player2[i], player2[(i + 1) % count2]);
        
    				}
    				
					strcpy(player2[count2-1], "\0");
					
					count2--;
	
					for(int b = 0; b < 27; b++)
					{
						if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
						{
							printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
							
						} else
						{
							continue;
						}
					}
					
					strcpy(currentcard, input);
					
					printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
					
				}
				} else if ((input[1] == currentcard[1]))
				{
					for(int i = 0; i < 27; i++)
					{
						if(strcmp(input, player2[i]) == 0)
						{
							pos = i;
						}
					}
				
					strcpy(player2[pos], "\0");
					
					for(int i=pos;i < count2;i++)
    				{
        				strcpy(player2[i], player2[(i + 1) % count2]);
        
    				}
					
					strcpy(player2[count2-1], "\0");
					
					count2--;
	
					for(int b = 0; b < 27; b++)
					{
						if(player2[b][0] >= 'A' && player2[b][0] <= 'Z')
						{
							printf("Card %d for Player 2 is: %s\n", (b + 1), player2[b]);
							
						} else
						{
							continue;
						}
					}
					
					strcpy(currentcard, input);
					
					printf("\n\n---------------- currentcard will be %s ----------------\n\n", currentcard);
					
				} else
				{
					goto inputforplayer2;	
				}
				if(count2 == 0)
				{
					break;
				}
							
	}
	if(count1 == 0)
	{
		printf("\nPlayer 1 Wins");
		
	} else
	{
		printf("\nPlayer 2 Wins");
	}
}