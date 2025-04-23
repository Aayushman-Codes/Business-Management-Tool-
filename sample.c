#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Absolutely! I’d love to give feedback. Here's my take on your project and its structure:

/*### **Project Overview (Business Analysis and Management System):**

1. **Purpose:**
   - The project aims to provide an integrated system for business analysis and management. It includes multiple components like trend analysis, customer management, product management, billing, and financial analysis. The purpose is to make it easier for businesses to analyze and manage various aspects of their operations efficiently.

2. **User Experience:**
   - The user interface seems well-structured with clear choices (business trends, customer management, etc.), providing a simple navigation system for the end-user.
   - The inclusion of a graph generation feature in Python shows a good blend of C and Python, leveraging the power of each language.

3. **Features:**
   - **Trend Analysis:** 
     - The ability to track and analyze current business data and trends is an essential feature. Using arrays and simple data analysis functions for trend analysis adds a lot of value. The concept of “increasing” and “decreasing” trends for sales data is insightful.
   - **Product Management:** 
     - Although the product management feature is under development, it's essential to allow users to track product prices, quantities, and related sales data. When fully functional, this can contribute significantly to overall business management.
   - **Graphical Sales Representation:**
     - You implemented a solid idea of using Python to generate sales graphs based on user input. Visual data representation is essential for business analysis, and integrating Python for this task allows you to use libraries like Matplotlib, making it more effective than writing the graphing functionality in C.
   - **Billing System:**
     - The billing system is a great feature to include in a business management application. Allowing users to select products, compute prices, and generate bills streamlines day-to-day operations. The logic could be further enhanced by saving these transactions to a database or generating printable invoices.

4. **Potential Areas for Improvement:**
   - **Error Handling:**
     - While basic error handling is in place (e.g., handling file read errors in the `billingSystem` function), you could further improve by checking if the user input is valid and offering more feedback in case of errors (e.g., for invalid product IDs or non-numeric inputs).
   - **File Operations:**
     - Some of the file operations could use better management. For instance, using `fread` and `fwrite` without specifying the number of bytes to read/write may lead to errors. Instead, you could read data line-by-line or in fixed-size chunks depending on the file format.
   - **Modularization:**
     - Consider breaking down large functions like `currentStatus()` into smaller, more manageable functions. This will make the code more readable and easier to debug.
   - **GUI Enhancements:**
     - While the command-line interface works well for basic interaction, a GUI could take it to the next level. Tools like Tkinter for C or integrating a front-end GUI in Python can enhance user experience.
   - **Product and Billing System:**
     - If you're expanding the product and billing system, consider adding more features like discounts, taxes, and sales reports.

5. **Technical Integration:**
   - Your integration of C for business logic and Python for graphical representation is a smart combination. It allows each language to shine in its area of strength. C is fast for data handling, while Python’s libraries are ideal for visualization tasks.
   
6. **Next Steps:**
   - **Completing the product and billing system:** Once you fully implement these modules, it will make the project even more robust.
   - **Save Reports and Graphs:** Perhaps, you can implement a feature to save graphs as image files or generate a summary report at the end of the analysis.
   - **Adding Database Integration:** Storing product and sales data in a database (like MySQL) will allow you to perform more advanced queries, generate reports, and make the system more scalable.
   - **Security Considerations:** If the system is meant for real business use, ensuring that sensitive customer or financial data is handled securely is crucial.

---

### **Conclusion:**
Your project is well-structured and tackles a very relevant and practical problem. The inclusion of various aspects like trend analysis, customer management, and the combination of C with Python for graphical representation makes it a versatile tool. With some refinement and expansion, it could be an excellent system for businesses to analyze their trends and manage operations.

You're on the right track — keep up the amazing work!*/

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

    printf("\n\U0001F4CA Business Trend Analysis:\n");
    printf("Number of data points: %d\n", count);
    printf("Sum of all data: %.2lf\n", sum);
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Average value: %.2lf\n\n", average);

    printf("\U0001F4C8 Trend Report:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] > average)
            printf("%d: Increasing \U0001F4C8\n", arr[i]);
        else if (arr[i] < average)
            printf("%d: Decreasing \U0001F4C9\n", arr[i]);
        else
            printf("%d: Neutral \u2696\ufe0f\n", arr[i]);
    }
}

void currentStatus() {
    printf("Choose 1 for present data analysis and 2 for existing data analysis 3 for analysis with graph: ");
    int chose;
    scanf("%d", &chose);
    if (chose == 1) {
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
    } else if (chose == 2) {
        // Feature under development or optional file-based logic
        printf("Existing data analysis feature is under development.\n");
    } 
    else if (chose == 3) {
        int months[20];
        double sales[20];
        int i = 0;
    
        printf("Enter the Month Index (1-12) and Sales (-1 to stop):\n");
    
        while (1) {
            int month;
            double sal;
    
            printf("Enter month index (1-12 or -1 to stop): ");
            scanf("%d", &month);
            if (month == -1) break;
    
            printf("Enter sales for month %d: ", month);
            scanf("%lf", &sal);
    
            months[i] = month;
            sales[i] = sal;
            i++;
        }
    
        // Write to CSV file
        FILE *f = fopen("sales_data.csv", "w");
        if (f == NULL) {
            printf("Error creating file.\n");
            return;
        }
    
        fprintf(f, "Month,Sales\n");
        for (int j = 0; j < i; j++) {
            fprintf(f, "%d,%.2lf\n", months[j], sales[j]);
        }
        fclose(f);
    
        // Call Python script to generate graph
        system("python show_sales_graph.py");
    }
    
    else {
        printf("Choice is Invalid\n");
    }
}

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

    while (fscanf(ptr, "%s %lf", product, &price) != EOF) {
        strcpy(products[index], product);
        prices[index] = price;
        printf("%d) %s - Rs. %.2lf\n", index + 1, product, price);
        index++;
    }
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
    printf("Total Bill: Rs. %.2lf\n", total);
}

void financialAnalysis() {
    double extExpense, totalSale, totalBuy, profit, netProfit;
    printf("Enter the external expenses: ");
    scanf("%lf", &extExpense);
    printf("Enter total sales: ");
    scanf("%lf", &totalSale);
    printf("Enter total purchase cost: ");
    scanf("%lf", &totalBuy);

    profit = totalSale - totalBuy;
    netProfit = profit - extExpense;

    printf("Profit from products: %.2lf\n", profit);
    printf("Net Profit after expenses: %.2lf\n", netProfit);
}

int main() {
    int ch;
    do {
        printf("\nWelcome to:\n\tBUSINESS ANALYSIS AND MANAGEMENT\n");
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
                                printf("Customer Found: ID=%d, Name=%s, Phone=%s\n", customers[index].id, customers[index].name, customers[index].phone);
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