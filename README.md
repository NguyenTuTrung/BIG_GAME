# Game Flappy_Dog
``` 
Nguyễn Tử Trung - 21020415.
Bài tập lớn của lớp lập trình nâng cao INT2215_1.
Sử dụng C / C ++, SDL2, SDL_ttf , SDL_image, SDL_mixer thư viện phát triển trên Visual Studio Code .
```
## Hướng dẫn cài đặt
### 1) Cài đặt:
- Chương trình sử dụng file project của VS Code.
- Hãy tải xuống đầy đủ [VS Code](https://code.visualstudio.com/) và các thư viện 
[SDL2](https://www.libsdl.org/download-2.0.php) và tải (SDL2-devel-2.0.22-mingw.tar.gz),
[SDL2_image](https://www.libsdl.org/projects/SDL_image/) và tải (SDL2_image-devel-2.0.5-mingw.tar.gz),
[SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/release/) và tải (SDL2_ttf-devel-2.0.18-mingw.tar.gz)
[SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/) và tải ( SDL2_mixer-devel-2.0.4-mingw.tar.gz)..
- Cài đặt MingGW-W64:
    + Click vào đường link để download (https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/seh/x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z/download).
    + Giải nén file vừa tải.
    + Copy thư mục (mingw64) vào <ROOTDIR> (Ví dụ D:\software).
    + Cài đặt đường dẫn PATH đến <ROOTDIR>\mingw64\bin
    + Sau đó có thể kiểm tra bằng cách gọi (g++) và (mingw32-make) trong terminal
- Tạo Makefile để chạy chương trình:
	+ Bạn có thể copy các file .dll từ các file tải [SDL2],[SDL2_image],[SDL2_ttf],[SDL2_mixer] vào file project.
    + Hoặc bạn có thể dùng các file .dll như trong Github: (https://github.com/NguyenTuTrung/Big_Game).
	+ Mở file project của VS Code (Folder chứa code của Big_Game) sao đó có thể đưa link include và lib của các file tải [SDL2],[SDL2_image],[SDL2_ttf],[SDL2_mixer] vào. ( Có thể đưa vào 1 folder (src) trong như trong Github : (https://github.com/NguyenTuTrung/Big_Game) ).
    + Bạn có thể tải Big_Game về và sử dụng thư mục src mak đã được tổng hợp đủ.
	+ Vào trong VS Code tạo Makefile và viết :
    all:
	g++	-I<ROOTDIR>/include	-L<ROOTDIR>/lib	-o	[File cần tạo] [Các file .cpp của chương trình] -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
			
### 2) Chạy chương trình:
- Mở 1 Terminal mới.
- Nhập lệnh (mingw32-make).
- Nhập lệnh [File cần tạo].exe xong bấm Tab

## Mô tả chung về trò chơi, các ý tưởng chính
### 1) Mô tả chung về trò chơi:
- Tên trò chơi: Flappy_Dog

- Cách chơi:
   + Nhấn nút SPACE hoặc nhấp chuột trái để khéo léo di chuyển đối tượng(Con chó) qua các cột.
   + Trong quá trình chơi có người chơi có thể tạm dừng trò chơi bằng nút Esc hoặc bằng cách nhấp chuột phải.
   + Trò chơi kết thúc khi người chơi để đối tượng(Con chó) cva chạm vào cột, đi lên vợt khung hoặc chạm vào mặt đất.
### 2) Các ý tưởng chính
 - Tốc độ xuất hiện của cột sẽ tăng dần theo khung điểm người chơi đạt được 
 - Người chơi có 3 mạng để sử dụng trong lượt chơi của mình
 - Hệ thống âm thanh
 - Hệ thống đồ họa bắt mắt
### 3) Các chức năng được cài đặt trong trò chơi:
- Hiệu ứng âm thanh khi: click chuột, va chạm, thua cuộc, ...
- Chức năng tắt(mở) âm thanh trong bảng khi tạm dừng trong quá trình chơi
- Người chơi có thể tiếp tục trò chơi với số điểm đã đạt được với điệu kiện mạng vẫn còn
- Nếu người chơi không thích thì có thể bắt đầu lại trò chơi với số điểm là 0 với điệu kiện mạng vẫn còn
- Hiện thị số điểm của người chơi, và số mạng còn lại của người chơi ở góc trái màn hình
- Video demo [tại đây](https://youtu.be/n1DTI7UyE1M)
### 4) Các kỹ thuật lập trình được sử dụng trong chương trình
- Kĩ thuật lập trình đồ họa, âm thanh bằng SDL 
- Kĩ thuật lập trình hướng đối tượng
- Kĩ thuật tách file 
- Các kĩ thuật  khác: Mảng, con trỏ, cấu trúc, lớp, cách tạo số ngẫu nhiên(vị trí ngẫu nhiên), vòng lặp các trạng thái của game, ....
### 5) Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình
a) Hướng phát triển:
- Phát triển thêm các tính năng:
  + Tạo thêm nhiều chế độ chơi như : 2 players, vừa di chuyển vừa ăn các đối tượng sự kiện khác,.....
  + Tạo bản thành tích qua các lần chơi(VD: Thành tích 5 lần chơi thắng nhanh nhất, kèm theo tên người chơi)

b) Điều tâm đắc: 
- Do là Game đầu tay nên vẫn còn nhiều sai sót, code chưa được tối ưu nhất, nhưng qua bài tập này nâng cao trình độ code rất nhiều, qua chương trình rút ra được nhiều kinh nghiệm trong cách làm bài tập lớn để các chương trình sau được hoàn thiện tốt hơn
- Thông qua chương trình học thêm được các kiến thức sau:
  + Biết được tiến trình tạo ra một game và cách vận hành của một game
  + Biết sử dụng SDL 2.0 để tạo một chương trình đồ họa có đồ họa và âm thanh
  + Củng cố kiến thức sử dụng ngôn ngữ lập trình C++

## Nguồn tham khảo và tài nguyên game
- Chương trình được xây dựng trên  [VS Code](https://code.visualstudio.com/). 
- Các thư viện [SDL](https://www.libsdl.org/).
- Tất cả các hình ảnh trong game được tải xuống từ Google Image.
- Âm thanh sử dụng trong game được tải xuống từ [Mixkit](https://mixkit.co/free-sound-effects/game/). 
- https://lazyfoo.net/tutorials/SDL/
- https://phattrienphanmem123az.com/
- https://wiki.libsdl.org/
