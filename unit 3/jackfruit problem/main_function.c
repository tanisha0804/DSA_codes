#include <stdio.h>
#include <stdlib.h>
#include "user_management.c"
#include "product_management.c"
#include "browsing_recommendations.c"

int main() {
    NODE *root = NULL;
    char user_id[50][50], user_name[50][50], product_id[50][50], product_name[50][50];
    int u, p;
    char upd_userId[50], upd_user_inf[50], upd_prodId[50], upd_prod_inf[50];

    printf("Enter the number of users you want to enter: ");
    scanf("%d", &u);
    for(int i = 0; i < u; i++) {
        printf("Enter user ID: ");
        scanf("%s", user_id[i]);
        printf("Enter user name: ");
        scanf("%s", user_name[i]);
        add_user(user_id[i], user_name[i]);
        printf("User Info: %s\n", get_user(user_id[i]));
    }

    printf("Enter the ID of the user to be updated and the info you want it to be updated to\n");
    printf("Enter user ID: ");
    scanf("%s", upd_userId);
    printf("Enter new user name: ");
    scanf("%s", upd_user_inf);
    update_user(upd_userId, upd_user_inf);
    printf("Updated User Info: %s\n", get_user(upd_userId));

    printf("Enter the number of products you want to enter: ");
    scanf("%d", &p);
    for(int i = 0; i < p; i++) {
        printf("Enter product ID: ");
        scanf("%s", product_id[i]);
        printf("Enter product name: ");
        scanf("%s", product_name[i]);
        add_product(product_id[i], product_name[i]);
        printf("Product Info: %s\n", get_product(product_id[i]));
    }

    printf("Enter the ID of the product to be updated and the info you want it to be updated to\n");
    printf("Enter product ID: ");
    scanf("%s", upd_prodId);
    printf("Enter new product name: ");
    scanf("%s", upd_prod_inf);
    update_product(upd_prodId, upd_prod_inf);
    printf("Updated Product Info: %s\n", get_product(upd_prodId));

    root = browsing(root, user_id[0], product_name[0]);
    root = browsing(root, user_id[0], product_name[1]);
    root = browsing(root, user_id[1], product_name[0]);
    root = browsing(root, user_id[0], product_name[2]);
    root = purchasing(root, user_id[0], product_name[1]);
    root = browsing(root, user_id[1], product_name[2]);

    printf("\nHistory for user1:\n");
    user_history(root,user_id[0]);

    printf("\nHistory for user2:\n");
    user_history(root,user_id[1]);

    generate_recommendations(root,user_id[1]);

    return 0;
}

