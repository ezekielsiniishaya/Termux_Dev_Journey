#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Max accounts reached.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = numAccounts + 1;
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;
    accounts[numAccounts] = newAccount;
    numAccounts++;
    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > numAccounts) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    accounts[accountNumber - 1].balance += amount;
    printf("Amount deposited successfully. New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > numAccounts) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }
    accounts[accountNumber - 1].balance -= amount;
    printf("Amount withdrawn successfully. New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void checkBalance() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > numAccounts) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[accountNumber - 1].accountNumber, accounts[accountNumber - 1].name, accounts[accountNumber - 1].balance);
}

int main() {
    int choice;
    while (1) {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
