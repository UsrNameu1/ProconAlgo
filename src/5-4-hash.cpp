#include<stdio.h>
#include<string.h>

class ATGCHashSet {
public:
    static const int STR_LENGTH = 14;

    ATGCHashSet() {
        int i;
        for (i = 0; i < BUCKET_NUM; i++) {
            bucket[i][0] = '\0';
        }
    }

    int hashByIdx(char str[], int idx) {
        int key = getKey(str);
        return (h1(key) + idx * h2(key)) % BUCKET_NUM;
    }

    bool find(char str[]) {
        long long key, i, hash;
        for ( i = 0;; i++) {
            hash = hashByIdx(str, i);
            if (strcmp(bucket[hash], str) == 0) return true;
            else if (strlen(bucket[hash]) == 0) return false;
        }
        return false;
    }

    bool insert(char str[]) { 
        long long key, i, hash;
        for (i = 0;; i++) {
            hash = hashByIdx(str, i);
            if (strcmp(bucket[hash], str) == 0) return true;
            else if (strlen(bucket[hash]) == 0) {
                strcpy(bucket[hash], str);
                return false;
            }
        }
        return false;
    }

private:
    static const int BUCKET_NUM = 1046527;

    char bucket[BUCKET_NUM][STR_LENGTH];

    int getChar(char ch) {
        if (ch == 'A') return 1;
        else if (ch == 'C') return 2;
        else if (ch == 'G') return 3;
        else if (ch == 'T') return 4;
        else return 0;
    }

    long long getKey(char str[]) {
        long long sum = 0, p = 1, i;
        for (i = 0; i < strlen(str); i++) {
            sum += p * getChar(str[i]);
            p *= 5;
        }
        return sum;
    }

    int h1(int key) { return key % BUCKET_NUM; }
    int h2(int key) { return 1 + (key % (BUCKET_NUM - 1)); }
};

int main() {
    int i, n, h;
    char str[ATGCHashSet::STR_LENGTH], com[9];
    auto *table = new ATGCHashSet();

    scanf("%d", &n);

    for (i = 0; i < n; i++ ) {
        scanf("%s %s", com, str);

        if (strcmp(com, "insert") == 0) {
            table->insert(str);
        } else if (strcmp(com, "find") == 0) {
            if (table->find(str)) printf("yes\n");
            else printf("no\n");
        } else {
            printf("some error occur");
            return 1;
        }
    }
    return 0;
}
