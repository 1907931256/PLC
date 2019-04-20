bool one = true;
int x_pin[8] = {10, 11, 12, 13, 14, 15, 16, 17};
int y_pin[8] = {2, 3, 4, 5, 6, 7, 8, 9};
bool x[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool y[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool xsc[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool ysc[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void pinReadWrite() { //引脚状态读入
    for (int i = 0; i < 8; i++) {
        x[i] = digitalWrite(x_pin[i]);
        y[i] = digitalWrite(y_pin[i]);
    }
}
void pinInit() { //引脚状态读入
    for (int i = 0; i < 8; i++) {
        pinMode(x_pin[i],INPUT);
        PinMode(y_pin[i],OUTPUT);
    }
}
void pinSC() { //保存上次旧值
    ysc[0] = y[0]; ysc[1] = y[1]; ysc[2] = y[2]; ysc[3] = y[3];
    ysc[4] = y[4]; ysc[5] = y[5]; ysc[6] = y[6]; ysc[7] = y[7];
    xsc[0] = x[0]; xsc[1] = x[1]; xsc[2] = x[2]; xsc[3] = x[3];
    xsc[4] = x[4]; xsc[5] = x[5]; xsc[6] = x[6]; xsc[7] = x[7];
}


void setup() {
pinInit();//引脚初始化
}

void loop() {
    pinReadWrite();//引脚状态读入
    //inputCode



    pinSC();//保存上次旧值
    one = false;//第一次为真
}
