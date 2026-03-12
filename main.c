#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bağlı liste node yapısı
typedef struct Node {
    char log[256];          // Log satırı
    struct Node* next;      // Sonraki node
} Node;

// Listenin başı
Node* head = NULL;

// Yeni log ekleme fonksiyonu
void addLog(const char* text) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Bellek hatası!\n");
        exit(1);
    }

    strcpy(newNode->log, text);
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Listeyi ekrana yazdırma fonksiyonu
void printLogs() {
    if(head == NULL) {
        printf("Liste boş.\n");
        return;
    }

    Node* temp = head;
    while(temp != NULL) {
        printf("%s", temp->log);  // fgets ile okunduğu için zaten \n var
        temp = temp->next;
    }
}

int main() {
    FILE* file = fopen("sample_syslog.txt", "r");
    if(file == NULL) {
        printf("Dosya bulunamadı! Lütfen 'sample_syslog.txt' dosyasının main.c ile aynı klasörde olduğundan emin olun.\n");
        return 1;
    }

    char line[256];

    while(fgets(line, sizeof(line), file) != NULL) {
        addLog(line);
    }

    fclose(file);

    // Bağlı listeyi ekrana yazdır
    printLogs();

    return 0;
}