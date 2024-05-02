
const int RED_PIN = 4;    // led đỏ
const int GREEN_PIN =5 ; // led xanh lá
const int BLUE_PIN = 6;  // led xanh dương
 
// Hằng số đợi giữa mỗi lần đổi trạng thái
 
int DELAY_TIME = 10;  // đơn vị là mili giây nhá - thử thay đổi số này xem sao :3
 
 
// Hàm setup
// Xem thêm về vòng đời các hàm trong Arduino
// http://arduino.vn/reference/setup-va-loop
void setup()
{
  // Khởi tạo các chân là OUTPUT (tất nhiên òi :D)
  // http://arduino.vn/reference/pinmode
  // http://arduino.vn/reference/thiet-dat-digital-pins-nhu-la-input-inputpullup-va-output
 
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}
 

void loop()
{
  // Gọi hàm displayAllBasicColors để thể hiện toàn bộ các màu cơ bản !
 

 
  // Đã chơi led rgb mà không biết đến hiệu ứng cầu vồng thì không thể chấp nhận được :3, vì vậy, mình chia sẻ cho các bạn hiệu ứng cầu vồng luôn
  // Gọi hàm showSpectrum để chạy hiệu ứng cầu vồng.
  showSpectrum();
}
 
 
// Cài đặt hàm displayAllBasicColors
 

// Cài đặt hàm showSpectrum
 
 
void showSpectrum()
{
  
  for (int i = 0; i < 768; i++)
  {
    showRGB(i);  // Call RGBspectrum() with our new x
    delay(10);   // Delay 10ms 
  }
}
 
 
// Cài đặt hàm showRGB(int color)
 
// Chúng ta sẽ cài đặt hàm showRGB để mỗi khi nhận một giá trị từ 0 - 767
// nó sẽ chuyển dần dầm các màu của con đèn led rgb thành các màu đỏ - cam - vàng - lục - lam - chàm - tím
 
// mình chia nó thành 3 khu
// đỏ - xanh lục
// xanh lục - xanh lam
// xanh lam - đỏ
 
// gồm có 4 mốc
// 0   = đỏ chét (đỏ 100%)
// 255 = xanh lục 100%
// 511 = xanh dương (100%)
// 767 = lại là đỏ chét
 
// Những con số nằm giữa các màu sẽ được tính toán theo công thức bên dưới (đọc dễ hiểu mà) để ra được các màu cần thiết
 
 
 
void showRGB(int color)
{
  int redPWM;
  int greenPWM;
  int bluePWM;
 
 
 
  if (color <= 255)          // phân vùng 1
  {
    redPWM = 255 - color;    // red đi từ sáng về tắt
    greenPWM = color;        // green đi từ tắt thành sáng
    bluePWM = 0;             // blue luôn tắt
  }
  else if (color <= 511)     // phân vùng 2
  {
    redPWM = 0;                     // đỏ luôn tắt
    greenPWM = 255 - (color - 256); // green đi từ sáng về tắt
    bluePWM = (color - 256);        // blue đi từ tắt thành sáng
  }
  else // color >= 512       // phân vùng 3
  {
    redPWM = (color - 512);         // red tắt rồi lại sáng
    greenPWM = 0;                   // green luôn tắt nhé
    bluePWM = 255 - (color - 512);  // blue sáng rồi lại tắt
  }
 
  // rồi xuất xung ra và chơi thôi :3
 
  analogWrite(RED_PIN, redPWM);
  analogWrite(BLUE_PIN, bluePWM);
  analogWrite(GREEN_PIN, greenPWM);
}
