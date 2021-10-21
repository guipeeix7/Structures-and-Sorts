#include <stdio.h>

int H()
{
    int loop = 0;
    scanf("%d", &loop);
    int textSize = 0;
    while (loop--)
    {
        char text[10000] = {0};
        int i = 0;
        int ordinals = 0;
        scanf("%s", text);
        getchar();

        while (text[i] != 0)
        {
            if (text[i] >= '0' && text[i] <= '9')
            {
                ordinals+= (int) text[i] - 48;
            }
            i++;
        }
        printf("%d\n", ordinals);
    }
}

int main()
{
    H();
    return 0;
}