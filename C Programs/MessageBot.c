#include <stdio.h>
#include <Windows.h>

void sendMsg(const char* msg, int n) {
    // Copy the message to the clipboard
    OpenClipboard(0);
    EmptyClipboard();
    HGLOBAL hClipboardData = GlobalAlloc(GMEM_DDESHARE, strlen(msg) + 1);
    char* pchData = (char*)GlobalLock(hClipboardData);
    strcpy(pchData, msg);
    GlobalUnlock(hClipboardData);
    SetClipboardData(CF_TEXT, hClipboardData);
    CloseClipboard();

    Sleep(3000);

    // Simulate key presses using the Windows API
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    for (int i = 0; i < n; i++) {
        // Press and release CTRL+V to paste the message from clipboard
        input.ki.wVk = VK_CONTROL;
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = 'V';
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_CONTROL;
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = 'V';
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        // Press and release ENTER to send the message
        input.ki.wVk = VK_RETURN;
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.wVk = VK_RETURN;
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        Sleep(500);
    }
}

int main() {
    char msg[100];
    int n;

    printf("Enter the Msg: ");
    fgets(msg, sizeof(msg), stdin);

    printf("How many times to Send: ");
    scanf("%d", &n);

    // Remove the trailing newline character from the message
    msg[strcspn(msg, "\n")] = 0;

    sendMsg(msg, n);

    return 0;
}
