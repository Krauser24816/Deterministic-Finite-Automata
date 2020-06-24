//Program to check for DFA acceptability
//In this program you can only enter string containig 0 or 1
//Options 24 and 25 would be able to accept numbers from 0 to 9

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

//Funtion which can process a given string
int process_string(void)
{
 int option_for_process,string_count,numb_of_char=0;
 int input_check=0,get_out;
 int loop_variable;
 int str_arr[50];
 //Some basic information
 printf("\nYou can enter string of max 50 characters\n");
 printf("After entering every character press enter to input that string character");
 printf("\nFor 24-25 you can only enter positive numbers.\n");
 printf("After entering each digit press enter to input it\n");
 //Label if wrong character is eneterd
 start1:
 fflush(stdin);
 printf("\nEnter your option which you have selected from menu\n");
 scanf("%d",&option_for_process);
 if(option_for_process>=1 && option_for_process<=25)
 {
  printf("Enter your string\n");
  printf("When your string is entered please input -1 as to terminate it\n");
  //Through this loop we can ensure that right caracter is entered
  while(input_check != -1)
  {
   fflush(stdin);
   scanf("%d",&str_arr[numb_of_char]);
   input_check=str_arr[numb_of_char];
   if(option_for_process>=1 && option_for_process<=23)
   {
    if(str_arr[numb_of_char]==1 || str_arr[numb_of_char]==0 || str_arr[numb_of_char]==-1)
     numb_of_char++;
    //If wrong character is entered pointer wil not be incremented
    else
    {
     printf("You have entered wrong letter,Please enter again\n");
     numb_of_char++;
     numb_of_char--;
    }
   }
   else
   {
    fflush(stdin);
    if(str_arr[numb_of_char]>=-1 && str_arr[numb_of_char]<=9)
     numb_of_char++;
    else
     printf("You have entered wrong letter,Please enter again\n");
    }
  }
 }
 else
 {
  printf("\nYou have entered wrong option,Please select again\n");
  goto start1;
 }
 string_count= numb_of_char -1;
 printf("\nString length = %d\n",string_count);
 printf("\nString:");
 for(loop_variable=0;loop_variable<=string_count-1;loop_variable++)
 {
  printf("%d",str_arr[loop_variable]);
 }
 printf("\nOption you choose = %d",option_for_process);
 //Here the string will be checked
 switch(option_for_process)
 {
 //Strings starting with 0
  case 1:
  {
   if(str_arr[0]==0)
    return 1;
   else
    return 0;
  }

  //Strings of exactly length 2
  case 2:
  {
   if(string_count==2)
    return 1;
   else
    return 0;
  }

  //Strings having even length
  case 3:
  {
   if(string_count%2==0)
    return 1;
   else
    return 0;
  }

  //Strings having 11 as substring
  case 4:
  {
   int ele_check;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==1)
    {
     if(str_arr[ele_check+1]==1)
      return 1;
    }
   }
    return 0;
  }

  //Strings having exactly 3 0's
  case 5:
  {
   int ele_check, zero_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
   }
   if(zero_counter==3)
    return 1;
   else
    return 0;
  }

  //Strings having atmost 3 0's
  case 6:
  {
   int ele_check, zero_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
   }
   if(zero_counter<=3)
    return 1;
   else
    return 0;
  }

  //Strings having atleast 3 0's
  case 7:
  {
   int ele_check, zero_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
   }
   if(zero_counter>=3)
    return 1;
   else
    return 0;
  }

  //Strings having even number of 0's
  case 8:
  {
   int ele_check, zero_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
   }
   if(zero_counter%2==0)
    return 1;
   else
    return 0;
  }

  //Strings having odd number of 0's
  case 9:
  {
   int ele_check, zero_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
   }
   if(zero_counter%2==1)
    return 1;
   else
    return 0;
  }

  //Strings starting with 10
  case 10:
  {
   if(str_arr[0]==1)
   {
    if(str_arr[1]==0)
     return 1;
    else
     return 0;
   }
   else
    return 0;
  }

  //Strings ending with 10
  case 11:
  {
   if(str_arr[string_count-1]==0)
   {
    if(str_arr[string_count-2]==1)
     return 1;
    else
     return 0;
   }
   else
    return 0;
  }

  //Strings having substring 10
  case 12:
  {
   int ele_check;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==1)
    {
     if(str_arr[ele_check+1]==0)
      return 1;
    }
   }
   return 0;
  }

  //Strings having number of 0's in multiple of 3
  case 13:
  {
   int ele_check,zero_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
   }
   if(zero_counter%3==0)
    return 1;
   else
    return 0;
  }

  //String either ending or beginning with 01
  case 14:
  {
   if(((str_arr[string_count-2]==0) && (str_arr[string_count-1]==1)) || ((str_arr[0]==0) && (str_arr[1]==1)))
    return 1;
   else
    return 0;
  }

  //Strings neither beginning nor ending with 01
  case 15:
  {
   if(((str_arr[string_count-2]==0) && (str_arr[string_count-1]==1)) || ((str_arr[0]==0) && (str_arr[1]==1)))
    return 0;
   else
    return 1;
  }

  //Strings having even number of 0's and even number of 1's
  case 16:
  {
   int ele_check, zero_counter=0, one_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
    else
     one_counter++;
   }
   if(zero_counter%2==0 && one_counter%2==0)
    return 1;
   else
    return 0;
  }

  //Strings having odd numbers of 0's and odd number of 1's
  case 17:
  {
   int ele_check, zero_counter=0, one_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
    else
     one_counter++;
   }
   if(zero_counter%2==1 && one_counter%2==1)
    return 1;
   else
    return 0;
  }

  //Strings having even number of 0's and odd number of 1's
  case 18:
  {
   int ele_check, zero_counter=0, one_counter=0;
   for(ele_check=0;ele_check<=string_count-1;ele_check++)
   {
    if(str_arr[ele_check]==0)
     zero_counter++;
    else
     one_counter++;
   }
   if(zero_counter%2==0 && one_counter%2==1)
    return 1;
   else
    return 0;
  }

  //Strings that accept all binary numbers divisible by 3
  case 19:
  {
   int rev_string_count=string_count-1;
   int ele_check=0,sum_binary=0;
   while(ele_check<string_count)
   {
    sum_binary += (str_arr[ele_check])*(pow(2,rev_string_count));
    ele_check++;
    rev_string_count--;
   }
   printf("\nNumber Generated = %d",sum_binary);
   if(sum_binary%3==0)
    return 1;
   else
    return 0;
  }

  //Strings that accept all binary numbers divisible by 4
  case 20:
  {
   int rev_string_count=string_count-1;
   int ele_check=0, sum_binary=0;
   while(ele_check<string_count)
   {
    sum_binary += (str_arr[ele_check])*pow(2,rev_string_count);
    ele_check++;
    rev_string_count--;
   }
   printf("\nNumber Generated = %d\n",sum_binary);
   if(sum_binary%4==0)
    return 1;
   else
    return 0;
  }

  //Strings containing 3 consecutive 0's
  case 21:
  {
   int ele_check;
   for(ele_check=0;ele_check<=string_count-3;ele_check++)
   {
    if(str_arr[ele_check]==0)
    {
     if(str_arr[ele_check+1]==0)
     {
      if(str_arr[ele_check+2]==0)
       return 1;
     }
    }
   }
   return 0;
  }

  //Strings having third symbol from right end is 1
  case 22:
  {
   if(str_arr[string_count-3]==1)
    return 1;
   else
    return 0;
  }

  /* Strings that accepts every block of 5 consecutive symbols having atleast
     two 0's */
  case 23:
  {
   int ele_check;
   int zero_counter=0, check_counter=0;
   if(string_count<5)
   {
    printf("\nSorry, your string have less than 5 symbols");
    printf("\nPlease select again");
    goto start1;
   }
   else
   {
   for(ele_check=0;ele_check<=string_count-5;ele_check++)
   {
    if(str_arr[ele_check]==0)
    {
     if(str_arr[ele_check+1]==0)
      zero_counter++;
     else if(str_arr[ele_check+2]==0)
      zero_counter++;
     else if(str_arr[ele_check+3]==0)
      zero_counter++;
     else if(str_arr[ele_check+4]==0)
      zero_counter++;
     else
      return 0;
    }

    else if(str_arr[ele_check+1]==0)
    {
     if(str_arr[ele_check+2])
      zero_counter++;
     else if(str_arr[ele_check+2]==0)
      zero_counter++;
     else if(str_arr[ele_check+3]==0)
      zero_counter++;
     else if(str_arr[ele_check+4]==0)
      zero_counter++;
     else
      return 0;
    }

    else if(str_arr[ele_check+2]==0)
    {
     if(str_arr[ele_check+3]==0)
      zero_counter++;
     else if(str_arr[ele_check+4]==0)
      zero_counter++;
     else
      return 0;
    }

    else if(str_arr[ele_check+3]==0)
    {
     if(str_arr[ele_check+4]==0)
      zero_counter++;
     else
      return 0;
    }
    else
     return 0;

    check_counter++;
   }
   if(check_counter==zero_counter)
    return 1;
   else
    return 0;
  }

  //Strings that accepts all decimal numbers divisible by 3
  case 24:
  {
   int rev_string_count=string_count-1;
   int ele_check=0, sum_decimal=0;
   while(ele_check<=string_count-1)
   {
    sum_decimal += (str_arr[ele_check])*(pow(10,rev_string_count));
    ele_check++;
    rev_string_count--;
   }
   printf("\nNumber you have entered= %d",sum_decimal);
   if(sum_decimal%3==0)
    return 1;
   else
    return 0;
  }

  //Strings that accepts all decimal numbers divisible by 4
  case 25:

  {
   int rev_string_count=string_count-1;
   int ele_check=0, sum_decimal=0;
   while(ele_check<=string_count-1)
   {
    sum_decimal += (str_arr[ele_check])*(pow(10,rev_string_count));
    ele_check++;
    rev_string_count--;
   }
   printf("\nNumber you have entered= %d",sum_decimal);
   if(sum_decimal%4==0)
    return 1;
   else
    return 0;
  }
 }
}
}

/* Below menu1(), menu2(), menu3(), menu4() are fuctions for printing menu
   for user in such a way that he/she is able to understand it clearly  */

//Options 1-10
void menu1(void)
{
 printf("\nDFA's that accepts all strings which contains (0,1) as alphabets:-");
 printf("\n1.Starts with 0");
 printf("\n2.Of length exactly 2");
 printf("\n3.Of even length");
 printf("\n4.Having 11 as substring");
 printf("\n5.Having exatly 3 0's");
 printf("\n6.Having atmost 3 0's");
 printf("\n7.Having atleast 3 0's");
 printf("\n8.Having even number of 0's");
 printf("\n9.Having odd number of 0's");
 printf("\n10.Starting with 10");
}

//Options 11-20
void menu2(void)
{
 printf("\n11.Ending with 10");
 printf("\n12.Having 10 as substring");
 printf("\n13.Having 0's in multiple of 3");
 printf("\n14.Either ending or beginning with 01");
 printf("\n15.Neither ending nor beginning with 01");
 printf("\n16.Having even number of 0's and even number of 1's");
 printf("\n17.Having odd number of 0's and odd number of 1's");
 printf("\n18.Having even number of 0's and odd number of 1's");
 printf("\n19.All binary numbers divisible by 3");
 printf("\n20.All binary numbers divisible by 4");
}

//Options 21-23
void menu3(void)
{
 printf("\n21.Containig 3 consecutive 0's");
 printf("\n22.Having 3rd symbol from right hand 1");
 printf("\n23.Block of 5 consecutive symbols having atleast two 0's");
}

//Optons 24 and 25
void menu4(void)
{
 printf("\n24.DFA that accepts all decimal numbers divisible by 3");
 printf("\n25.DFA that accepts all decimal numbers divisible by 4");
}

/*In main fuction I would generally be calling all fuctions in an organised
  manner so that the output would be easily understood */
void main()
{
 clrscr();
 char option, option_for_menu;
 int input_to_continue,menu_again;
 int returned_value;
 printf("\nTo start input 1\nTo leave press any other key\n");
 scanf("%d",&input_to_continue);
 while(input_to_continue==1)
 {
  printf("\na.Menu\nb.Enter String\nc.To clear screen\nd.Exit\n");
  printf("\nEnter your option\n");
  fflush(stdin);
  scanf("%c",&option);
  //Main menu
  switch(option)
  {
   //For printing menu
   case 'a':
	     printf("\nI wanted to offer you wide range of DFA's. ");
	     printf("\nSo I divided the list into 4 parts.");
	     printf("\nYou can choose as you wish");
	     printf("\n**NOTE:-FOR 24 AND 25 YOU HAVE TO ENTER NORMAL NUMBERS**");
	     start:
	     fflush(stdin);
	     printf("\nFor 1-10 input 1\nFor 11-20 input 2\nFor 21-23 input 3");
	     printf("\nFor 24 and 25 input 4\n");
	     start3:
	     fflush(stdin);
	     scanf("%d",&option_for_menu);
	     switch(option_for_menu)
	     {
	      case 1: menu1();
		      break;
	      case 2: menu2();
		      break;
	      case 3: menu3();
		      break;
	      case 4: menu4();
		      break;
	      default:
		     {
		      printf("You have entered wrong choice,Please select again\n");
		      goto start3;
		     }
	     }
	     printf("\nIf you want to see menu again then input 9\n");
	     printf("\nIf you want to exit input any other key\n");
	     scanf("%d",&menu_again);
	     if(menu_again==9)
	      goto start;
	     else
	      break;

   //For string processing
   case 'b': returned_value=process_string();
	     if(returned_value==1)
	      printf("\nANSWER-STRING IS ACCEPTED");
	     else
	      printf("\nANSWER-STRING IS REJECTED");
	     break;

   //For clearing screen
   case 'c': clrscr();
	     break;

   //For exiting
   case 'd': exit(0);
	     break;

   default:printf("\nYou have entered wrong choice\n");
  }
  printf("\nDo you want to continue?\nInput 1 to continue\nTo leave press any other key\n");
  scanf("%d",&input_to_continue);
 }
 getch();
}




