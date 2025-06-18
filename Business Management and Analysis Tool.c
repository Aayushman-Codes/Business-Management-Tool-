#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>

#include<math.h>


#define MAX 100

typedef struct {
    int id;
    char name[50];
    char phone[15];
} Customer;

// Function to sort customers by ID (Selection Sort)
void sortCustomers(Customer c[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (c[j].id < c[minIndex].id) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Customer temp = c[i];
            c[i] = c[minIndex];
            c[minIndex] = temp;
        }
    }
}

// Binary search function by ID
int binarySearch(Customer c[], int n, int targetID) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (c[mid].id == targetID)
            return mid;
        else if (c[mid].id < targetID)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Function to display all customer details
void displayCustomers(Customer c[], int n) {
    printf("\nAll Customers:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", c[i].id);
        printf("Name: %s\n", c[i].name);
        printf("Phone: %s\n", c[i].phone);
        printf("-------------------\n");
    }
}
//for input linear data analysis
void analyst(int arr[], int size) {
    if (size <= 0) {
        printf("No data to analyze.\n");
        return;
    }

    double sum = 0;
    int count = 0;
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
        sum += arr[i];
        count++;
    }

    double average = sum / count;

    printf("\n------- Business Trend Analysis:---------\n");
    printf("* Number of data points: %d\n", count);
    printf("* Sum of all data: %.2lf\n", sum);
    printf("* Maximum value: %d\n", max);
    printf("* Minimum value: %d\n", min);
    printf("* Average value: %.2lf\n\n", average);

    printf("Trend Report:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] > average)
            printf("%d:->Increasing...\n", arr[i]);
        else if (arr[i] < average)
            printf("%d:->Decreasing ...\n", arr[i]);
        else
            printf("%d:->Neutral ....\n", arr[i]);
    }
    printf("------------------------------------");
}
//current trend
void currentStatus() {
    printf("Choose \n1)For present data analysis \n2) for analysis with graph: ");
    int chose;
    scanf("%d", &chose);
    if (chose == 1) {
        printf("\n Data should be linear type(array of interger (like no. of iteams, money...)):\n");
        printf("Add Data (end input with -1):\n");
        int arr[100];
        int i = 0;
        while (1) {
            int data;
            scanf("%d", &data);
            if (data == -1) break;
            arr[i++] = data;
        }
        analyst(arr, i);
    }
     if (chose == 2) {
        int months[20];
        double sales[20];
        int i = 0;

        SetConsoleOutputCP(CP_UTF8); // Set UTF-8 before any graph output

        printf("Enter the Month Index (1-12) and Sales (-1 to stop):\n");

        while (1) {
            int month;
            double sal;

            printf("Enter month index (1-12 or -1 to stop): ");
            scanf("%d", &month);
            if (month == -1) break;

            printf("Enter sales amount for month %d: ", month);
            scanf("%lf", &sal);

            months[i] = month;
            sales[i] = sal;
            i++;
        }

        printf("\n--- Dotted Sales Graph ---\n");

        for (int j = 0; j < i; j++) {
            printf("Month %2d: ", months[j]);

            int dots = (int)(fabs(sales[j]) / 100); // Absolute value for dots

            if (sales[j] > 0) {
                for (int k = 0; k < dots; k++) {
                    printf("■");
                }
            } else if (sales[j] < 0) {
                for (int k = 0; k < dots; k++) {
                    printf("⬤");  // Use a different symbol for negative (or "--")
                }
            } else {
                printf("[No Sales]");
            }

            printf(" (%.2lf)\n", sales[j]);  // Show actual sales
        }
    }
}
//product management function with display and adding products
void productManagement() {
    printf("Choose choice -->\n1) All products\n2) Add Product\n");
    int pc;
    scanf("%d", &pc);
    if (pc == 1) {
        FILE *ptr = fopen("product.txt", "r");
        if (ptr == NULL) {
            printf("Error in file\n");
            return;
        }
        char ch;
        while ((ch = fgetc(ptr)) != EOF) {
            putchar(ch);
        }
        fclose(ptr);
    } else if (pc == 2) {
        FILE *ptr = fopen("product.txt", "a");
        if (ptr == NULL) {
            printf("Error in file\n");
            return;
        }
        char data[50];
        double rate;
        printf("Enter the product name: ");
        scanf("%s", data);
        printf("Enter the price of product: ");
        scanf("%lf", &rate);
        fprintf(ptr, "%s %.2lf\n", data, rate);
        fclose(ptr);
    }
}
//billing function to display the total bill
void billingSystem() {
    printf("Billing System - choose products by entering their indexes (end with -1):\n");
    FILE *ptr = fopen("product.txt", "r");
    if (ptr == NULL) {
        printf("Error in file\n");
        return;
    }

    char product[50];
    double price;
    int index = 0, chosen[10], chosenCount = 0;
    char products[100][50];
    double prices[100];
    printf("\n----------------MENU-----------------------\n");
    while (fscanf(ptr, "%s %lf", product, &price) != EOF) {
        strcpy(products[index], product);
        prices[index] = price;
        printf("%d) %s - Rs. %.2lf\n", index + 1, product, price);
        index++;
    }
    printf("\n--------------------------------------------\nEnter choice:");
    fclose(ptr);

    int sel;
    double total = 0.0;
    while (1) {
        scanf("%d", &sel);
        if (sel == -1) break;
        if (sel >= 1 && sel <= index) {
            total += prices[sel - 1];
        } else {
            printf("Invalid selection\n");
        }
    }
    printf("\n---------------------------------\n");
    printf("Total Bill: Rs.%.2lf\n", total);
    printf("\n---------------------------------\n");
}
//financial analysis

void financialAnalysis() {
    double extExpense, totalSale, totalBuy, profit, netProfit;
    printf("\n------------------Financial Analysis--------------------\n");
    printf("* Enter the external expenses: ");
    scanf("%lf", &extExpense);
    printf("* Enter total sales: ");
    scanf("%lf", &totalSale);
    printf("* Enter total purchase cost: ");
    scanf("%lf", &totalBuy);


    profit = totalSale - totalBuy;
    netProfit = profit - extExpense;

    printf("* Profit from products: %.2lf\n", profit);
    printf("* Net Profit after expenses: %.2lf\n", netProfit);
    printf("\n---------------------------------------------------------\n");
}

int main() {
    int ch;
    printf("\nWelcome:\n\tEntering Application:.....");
    Sleep(5000);
    for(int i=0;i<10;i++){
        printf("\n");
    }
    do {
        printf("\n\t--------:| BUSINESS ANALYSIS AND MANAGEMENT |------------\n");
        printf("Choose an option below:\n");
        printf("1) Current Business Trend Status\n");
        printf("2) Customer Management\n");
        printf("3) Product Management\n");
        printf("4) Billing System\n");
        printf("5) Financial Analysis\n");
        printf("6) Exit\n");

        scanf("%d", &ch);

        switch (ch) {
            case 1:
                currentStatus();
                break;
            case 2:
            {
                Customer customers[MAX];
                int n = 0, choice;
                while (1) {
                    printf("\n----- Customer Management -----\n");
                    printf("1. Add Customer\n");
                    printf("2. Search Customer by ID\n");
                    printf("3. Display All Customers\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if (choice == 4) break;

                    switch (choice) {
                        case 1:
                            if (n < MAX) {
                                printf("Enter ID: ");
                                scanf("%d", &customers[n].id);
                                printf("Enter Name: ");
                                scanf(" %[^\n]", customers[n].name);

                                printf("Enter Phone: ");
                                scanf("%s", customers[n].phone);
                                n++;
                                sortCustomers(customers, n);
                            } else {
                                printf("Customer limit reached.\n");
                            }
                            break;
                        case 2:
                        {
                            int targetID;
                            printf("Enter Customer ID to search: ");
                            scanf("%d", &targetID);
                            int index = binarySearch(customers, n, targetID);
                            if (index != -1) {
                                printf("\n--------------------------------------------------------------------\n");
                                printf("Customer Found:| ID=%d,| Name=%s | Phone=%s |\n", customers[index].id, customers[index].name, customers[index].phone);
                                printf("\n--------------------------------------------------------------------\n");
                            } else {
                                printf("Customer not found.\n");
                            }
                            break;
                        }
                        case 3:
                            displayCustomers(customers, n);
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                }
                break;
            }
            case 3:
                productManagement();
                break;
            case 4:
                billingSystem();
                break;
            case 5:
                financialAnalysis();
                break;
            case 6:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (ch != 6);

    return 0;
}