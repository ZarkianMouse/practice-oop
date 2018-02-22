/* Externals:
   tps, NV[], NVS[][] */

int get_input()
{
  int i,j;              // counting variables
  char *word[2];        // first and second string
  const char  *s;
  //std::cout << "\nTell me what to do? \n";
  std::cin.ignore();
  std::cout << "Passed keyboard buffer....\n";
  printf("\nTell me what to do? \n ");
  

  //std::getline(std::cin, tps1, '\n');
  std::cout << "w1 = " << *w1 << '\n'
            << "w2 = " << *w2 << '\n';

  for (i=0;i<length(tps);i++) tps[i]=toupper(tps[i]);
  i = 0;
  while (tps[i]==' ' && tps[i]!='\0') i++;  // go to first word
  word[0] = tps+i;
  while (tps[i]!=' ' && tps[i]!='\0') i++;  // go to next space
  while (tps[i]==' ' && tps[i]!='\0') i++;  // go to next word
  word[1] = tps+i;
  for (j=0;j<2;j++) // no more than LN chars 
  {
    i = 0;
    while(word[j][i]!=' ' && word[j][i]!='\0' && i<LN) i++;
    word[j][i]='\0';
  }
  for (i=0;i<2;i++)
  {
    NV[i] = 0;
    if (word[i][0]!='\0')
    {
      for (j=0;j<NL;j++)
      {
	s = NVS[i][j];
	if (s[0] == '*') s++;  /* skip special char */
	if (comparestring(word[i],s)==0)
	{
	  NV[i] = j;
	  j = NL;
	  while (NVS[i][NV[i]][0] == '*') NV[i]--;
	}
      }
    }
  }
  if ((NV[0] < 1) || (word[1][0]!='\0' && NV[1] < 1))
  {
    printf("You use word(s) I don't know.!\n");
    return(1);
  }
  else return(0);
}


/* Can I carry or drop it? If so, do it. */
void carry_drop()
{
  int ll,i,j,l,k;

  if ((NV[0] == 10 || NV[0] == 18) && (!f3))
  {
    if (NV[1] == 0)
    {
      printf("What?\n");
      f = 0;
    }
    else
    {
      if (NV[0] == 10)
      {
	l = 0;
	for (i=0;i<IL;i++) if (IA[i] == -1) l++;
      }
      if (NV[0] == 10 && l >= MX)
      {
	printf("I've too much to carry!\n");
	f = 0;
      }
      else
      {
	k = 0;
	for (j=0;j<IL;j++)
	{
	  ll = length(IAS[j]) - 1;
	  if (IAS[j][ll] == '/')
	  {
	    copystring(tps,IAS[j]);
	    tps[ll] = '\0';     /* get one shorter */
	    while (ll>1)
	    {
	      ll--;
	      if (tps[ll] == '/')
	      {
		ll++;   /* first char in item name */
		tps[ll+LN] = '\0';      /* make sure string is no longer than 3 chars */
		if (comparestring(tps+ll,NVS[1][NV[1]])==0)
		{
		  if (NV[0] == 10)
		  {
		    if (IA[j] != r) k = 2;
		    else
		    {
		      IA[j] = -1;
		      k = 3;
		      printf("OK, \n");
		      j = IL;
		    }
		  }
		  else
		  {
		    if (IA[j] != -1) k=1;
		    else
		    {
		      IA[j] = r;
		      k = 3;
		      printf("OK, \n");
		      j = IL;
		    }
		  }
		}
		ll = 1;
	      }
	    }
	  }
	}
	if (k == 1) printf("I'm not carrying it!\n");
	if (k == 2) printf("I don't see it here.\n");
	if (k == 0)
	{
	  if (!f3)
	  {
	    printf("It's beyond my power to do that.\n");
	    f = 0;
	  }
	}
	else f = 0;
      }
    }
  }
  if (f) printf("I don't understand your command.\n");
  else if (!f2) printf("I can't do that yet.\n");
}


int length(const char *s)
{
  int i;

  i = 0;
  while (s[i] != '\0') i++;
  return(i);
}

void copystring(char *dest, const char *source)
{
  int i;

  i = 0;
  while (source[i]!='\0')
  {
    dest[i] = source[i];
    i++;
  }
  dest[i] = '\0';
}

int comparestring(const char *s1, const char *s2)
{
  int i;

  i = 0;
  while (s1[i]==s2[i] && s1[i]!='\0') i++;
  if (s1[i]=='\0' || s2[i]=='\0') return(0); else return(1);
}
