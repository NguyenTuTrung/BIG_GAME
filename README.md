# Game Flappy_Dog
``` 
Nguyễn Tử Trung - 21020415.
Bài tập lớn của lớp lập trình nâng cao INT2215_1.
Sử dụng C / C ++, SDL2, SDL_ttf , SDL_image, SDL_mixer thư viện phát triển trên Visual Studio Code .
```
## Hướng dẫn cài đặt
1. Cài đặt:
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
			
2. Chạy chương trình:
- Mở 1 Terminal mới.
- Nhập lệnh mingw32-make.
- Nhập lệnh ./[File cần tạo].exe

## Các chức năng
1. Màn hình Chào: 
- Bắt đầu Game bằng cách nhấp chuột ( hoặc nút SPACE ) để bắt đầu trò chơi.
- Nhấn nút tắt ở góc trên cửa sổ để tắt chương trình.
2. Màn hình chơi:
- Các đối tượng:
	+ Có hình đối tượng (con chó) để người chơi điều khiển.
	+ Các cột di chuyển đến để làm chướng ngại vật .
- Số điểm đang có và số mạng ở góc trên phía trái màn hình.
- Tốc độ sẽ tằng dần theo khung điểm bạn đạt được.
3. Màn hình kết thúc game:
- Có thể thực hiện 2 thao tác:
	+ Ấn nút Replay để chơi lại ván mới với số điểm bằng 0 với điều kiện số mạng vẫn còn.
	+ Ấn nút Continue để chơi lại ván mới với số điểm đã đạt được điều kiện số mạng vẫn còn. 
## Hướng dẫn chơi
- Các bạn điều khiển đối tượng (con chó) tránh các cột, click chuột(hoặc SPACE) để đưa đối tượng (con chó) đi lên, với mỗi lần vượt qua cột bạn sẽ được thêm một điểm.  
## Nguồn tham khảo và tài nguyên game
- Chương trình được xây dựng trên  [VS Code](https://code.visualstudio.com/). 
- Các thư viện [SDL](https://www.libsdl.org/).
- Tất cả các hình ảnh trong game được tải xuống từ Google Image.
- Âm thanh sử dụng trong game được tải xuống từ [Mixkit](https://mixkit.co/free-sound-effects/game/). 
- https://lazyfoo.net/tutorials/SDL/
- https://phattrienphanmem123az.com/
- Video demo: 
