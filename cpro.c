#include<stdio.h>
#include<string.h>

//structure

struct Cart
{
    char item[50];
    int qty;
    float price;
    float amount;
};

//function declaration
// void showmenu();
// void addItem(struct Cart cart[], int *count);

// void deleteItem(struct Cart cart[], int *count);

// void printBill(struct Cart cart[], int count);1
// void admin();


void showMenu();

void addItem(struct Cart *cart, int *count);

void deleteItem(struct Cart *cart, int *count);

void printBill(struct Cart *cart, int count);

void admin();

int main()
{
    struct Cart cart[20];
    int count = 0;
    int choice;

    do
    {
        printf("\n================ SHIVANSH SNACK CENTER ====================\n");

        printf("1. Customer\n");
        printf("2. Admin\n");
        printf("0. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                int customerChoice;
                
                do
                {
                    printf("\n1. Show Menu\n");
                    printf("2. Add Item\n");
                    printf("3. Delete Item\n");
                    printf("4. Print Bill\n");
                    printf("0. Back\n");

                    printf("Enter Choice: ");
                    scanf("%d",&customerChoice);

                    switch (customerChoice)
                    {
                        case 1:
                            showMenu();
                            break;
                        
                        case 2:
                            addItem(cart, &count);
                            break;
                        
                        case 3:
                            deleteItem(cart, &count);
                            break;

                        case 4:
                            printBill(cart, count);
                            break;
                        
                        case 0:
                            break;

                        default:
                            printf("Invalid Choice\n");
                    }
                } while (customerChoice != 0);

                break;    
            }

            case 2:
                admin();
                break;
            
            case 0:
                printf("Thank You\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 0);

    return 0;
}
void showMenu()
{
    printf("\n================================ FOOD MENU ================================\n");

    printf("1. Pizza                 Rs.150\n");
    printf("2. Kachori               Rs.17\n");
    printf("3. Cold Drink            Rs.20\n");
    printf("4. Coffee                Rs.40\n");
    printf("5. Chai                  Rs.15\n");
    printf("6. Sandwich              Rs.60\n");
    printf("7. Misal Pav             Rs.120\n");
    printf("8. Vada Pav              Rs.20\n");
}

void addItem(struct Cart *cart, int *count)       
{
    int choice;

    showMenu();
    printf("Enter Food Choice: ");
    scanf("%d", &choice);

    printf("Enter Quantity: ");
    scanf("%d", &cart[*count].qty);

    switch(choice)
    {
        case 1:
            strcpy(cart[*count].item, "Pizza");
            cart[*count].price = 150;
            break;


        case 2:
            strcpy(cart[*count].item,  "Kachori");
            cart[*count].price = 17;
            break;

        
        case 3:
            strcpy(cart[*count].item, "Cold Drink");
            cart[*count].price = 20;
            break;

        
        case 4:
            strcpy(cart[*count].item, "Coffee");
            cart[*count].price = 40;
            break;

        
        case 5:
            strcpy(cart[*count].item, "Chai");
            cart[*count].price = 15;
            break;


        case 6:
            strcpy(cart[*count].item, "Sandwich");
            cart[*count].price = 60;
            break;


        case 7:
            strcpy(cart[*count].item, "Misal Pav");
            cart[*count].price = 120;
            break;


        case 8:
            strcpy(cart[*count].item, "Vada Pav");
            cart[*count].price = 20;
            break;

        default:
            printf("Invalid Choice!\n");
            return;
    }

    cart[*count].amount =
        cart[*count].price * cart[*count].qty;

    printf("Item Added Successfully!\n");

    (*count)++;
}

void deleteItem(struct Cart *cart, int *count)
{
    int number;
    int i;

    if(*count == 0)
    {
        printf("Cart is Empty!\n");
        return;
    }

    printf("\n===== CART ITEMS =====\n");

    for(i = 0; i < *count; i++)
    {
        printf("%d. %s\n", i + 1, cart[i].item);
    }

    printf("Enter Item Number to Delete: ");
    scanf("%d", &number);

    if(number < 1 || number > *count)
    {
        printf("Invalid Item Number!\n");
        return;
    }

    for(i = number - 1; i < *count - 1; i++)
    {
        cart[i] = cart[i + 1];
    }

    (*count)--;

    printf("Item Deleted Successfully!\n");
}
void printBill(struct Cart *cart, int count)
{
    FILE *fp;

    float total = 0;
    int i;

    fp = fopen("bill.txt", "w");

    printf("\n===== BILL =====\n");

    fprintf(fp, "===== SHIVANSH SNACK CENTER =====\n");

    for(i = 0; i < count; i++)
    {
        printf("%s  Qty:%d  Amount:%.2f\n",
               cart[i].item,
               cart[i].qty,
               cart[i].amount);

        fprintf(fp,
                "%s Qty:%d Amount:%.2f\n",
                cart[i].item,
                cart[i].qty,
                cart[i].amount);

        total = total + cart[i].amount;
    }

    printf("\nTotal Bill = Rs.%.2f\n", total);

    fprintf(fp, "\nTotal Bill = Rs.%.2f\n", total);

    fclose(fp);

    printf("Bill Saved in bill.txt\n");
}
void admin()
{
    int password;

    printf("Enter Admin Password: ");
    scanf("%d", &password);

    if(password == 1234)
    {
        printf("\nWelcome Admin!\n");
        printf("Password is Correct.\n");
    }
    else
    {
        printf("Wrong Password!\n");
    }
}