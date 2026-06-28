#include <stdio.h>
#include <string.h>

#define MAX 50

struct Ticket {
    int seatNo;
    char name[50];
    int booked; // 0 = available, 1 = booked
};

int main() {
    struct Ticket t[MAX];
    int i, choice, seat, found;

    // Initialize seats
    for(i = 0; i < MAX; i++) {
        t[i].seatNo = i + 1;
        t[i].booked = 0;
    }

    do {
        printf("\n===== TICKET BOOKING SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. View Bookings\n");
        printf("3. Cancel Ticket\n");
        printf("4. Available Seats\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter seat number (1-50): ");
                scanf("%d", &seat);

                if(seat < 1 || seat > MAX) {
                    printf("❌ Invalid seat number!\n");
                    break;
                }

                if(t[seat-1].booked) {
                    printf("❌ Seat already booked!\n");
                } else {
                    printf("Enter your name: ");
                    scanf("%s", t[seat-1].name);
                    t[seat-1].booked = 1;
                    printf("✅ Ticket booked successfully!\n");
                }
                break;

            case 2:
                printf("\n--- Booked Tickets ---\n");
                found = 0;
                for(i = 0; i < MAX; i++) {
                    if(t[i].booked) {
                        printf("Seat: %d | Name: %s\n",
                               t[i].seatNo, t[i].name);
                        found = 1;
                    }
                }
                if(!found) printf("No bookings yet!\n");
                break;

            case 3:
                printf("Enter seat number to cancel: ");
                scanf("%d", &seat);

                if(seat < 1 || seat > MAX) {
                    printf("❌ Invalid seat number!\n");
                    break;
                }

                if(!t[seat-1].booked) {
                    printf("❌ Seat not booked!\n");
                } else {
                    t[seat-1].booked = 0;
                    printf("✅ Ticket cancelled!\n");
                }
                break;

            case 4:
                printf("\n--- Available Seats ---\n");
                for(i = 0; i < MAX; i++) {
                    if(!t[i].booked) {
                        printf("%d ", t[i].seatNo);
                    }
                }
                printf("\n");
                break;

            case 5:
                printf("🙏 Exiting...\n");
                break;

            default:
                printf("❌ Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}