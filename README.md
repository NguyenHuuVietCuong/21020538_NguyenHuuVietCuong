# 21020538_NguyenHuuVietCuong
BÁO CÁO KẾT QUẢ BÀI TẬP CUỐI KHÓA 

Nguồn tham khảo: 
https://github.com/thanhtvt/minesweeperSDL/tree/Minesweeper-(so-called)/Minesweeper_with_SDL
https://www.youtube.com/watch?v=c8wswUEfnrQ
https://lazyfoo.net/tutorials/SDL/index.php

1.	Hướng dẫn cài đặt ( cách lấy chương trình về, tất cả các câu lệnh, cài đặt để có thể chạy được chương trình ): 
  - Tải về tất cả các file được đính kém và cho file Mine_Sweeper.exe.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

2.	Mô tả chung về trò chơi, các ý tưởng chính: 
  -	Mô tả chung về trò chơi:
  -	Người chơi bắt đầu trò chơi với một bản đồ hay bảng với tất cả các ô bị ẩn, bằng việc tương tác với các ô, người chơi sẽ chiến thắng nếu tìm được và mở hết tất cả những ô không chứa mìn, ngược lại, nếu người chơi chọn mở một ô chứa mìn thì trò chơi sẽ kết thúc. 
  -	Người chơi có thể tương tác với trò chơi bằng cách nhấn chuột trái hay chuột phải vào ô tùy theo mục đích. Chuột trái giúp người chơi mở một ô đang ẩn, ô này sẽ có hai khả năng xảy ra, nếu đó là mìn thì lập tức trò chơi sẽ kết thúc, nếu là ô an toàn, nó sẽ hiển thị một con số để biểu thị xung quanh nó đang có bao nhiêu quả mìn ( Ví dụ như ô có chỉ số là 3 thì tức là trong vòng 8 ô bao quanh nó sẽ có 3 ô chứa mìn, trường hợp đặc biệt là xung quanh không có mìn thì thay thì hiển thị số 0, ô sau khi mở sẽ hiển thị rỗng và số hiển thị tối đa sẽ là 8, biểu thị cho việc tất cả các ô xung quanh ô đó đều chứa mìn ). Mặt khác, chuột phải giúp người chơi đặt biểu tượng một lá cờ lên ô đó, thường được sử dụng để hỗ trợ người chơi khi họ muốn đánh dấu một ô họ cho rằng chứa mìn, giúp dễ dàng hơn trong việc quan sát và tránh bấm nhầm vào ô chứa mìn ( việc đặt cờ cho một ô sẽ không cho phép người chơi nhấn chuột trái vào ô đó nữa ).
  -	Các ý tưởng chính: 
  -	Ý tưởng khởi tạo trò chơi:
  -	Sau khi đã thực hiện các lựa chọn ở Menu, trò chơi sẽ tạo ra 2 bảng, một bảng sẽ chứa đáp án của trò chơi ( bảng này sẽ lưu dữ liệu của trò chơi sau khi tạo mìn ngẫu nhiên và sẽ chỉ hiển thị khi người chơi tự tìm ra vị trí của tất cả các ô chứa mìn hoặc thua cuộc ), bảng còn lại là bảng sẽ được hiển thị với người chơi để nhận vào tương tác và thực hiện cập nhật kết quả của mỗi tương tác đó . 
  -	Hai bảng sẽ được tạo ra qua việc sử dụng mảng 2 chiều và cùng chứa dữ liệu là kiểu biến int. Bảng ẩn ( giờ sẽ được gọi là board ), khi ta chưa thực hiện hàm sinh mìn ngẫu nhiên thì mặc định giá trị ban đầu của các ô sẽ là 0, sau đó bảng sẽ chứa các giá trị từ 1 đến 9, với ô có giá trị là 9 đồng nghĩa với việc bản thân nó chứa mìn, còn lại các ô mang chỉ số từ 1 đến 8 biểu thị cho số ô có mìn ở xung quanh nó. Bảng được hiển thị ( từ giờ sẽ gọi là sBoard ) sẽ được khởi tạo với tất cả các ô đều có giá trị là 10, biểu thị cho việc ô đang bị ẩn. Nhấn chuột trái vào một ô sẽ mở ô đó, đồng thời gán cho nó giá trị là một số từ 1 đến 9 tương ứng với vị trí của nó trong board, ngược lại, nhấn chuột phải sẽ gán cho ô đó giá trị là 11, biểu thị cho việc nó đã được đặt cờ. 
  -	Về việc thực hiện sinh mìn ngẫu nhiên, cho chạy vòng lặp while với điều kiện dừng là số mìn đã được đặt bằng tổng số mìn mặc định cho mỗi chế độ chơi. Chọn ra các ô ngẫu nhiên dựa vào việc sinh ra ngẫu nhiên các tọa độ, nếu giá trị của ô được chọn là 9, biểu thị cho việc ô này đã chứa mìn thì ta sẽ bỏ qua và tiếp tục đi tìm các ô khác. Ngược lại, nếu giá trị của ô khác 9 tức là ô đó chưa chứa mìn, ta sẽ đặt mìn cho ô sau đó tăng biến đếm số mìn lên một đồng thời tăng giá trị (chỉ số) của các ô xung quanh ô đó lên một.

  -	Xử lí tương tác với trò chơi: 
  -	Với các lựa chọn trong Menu, Emote ( Biểu cảm sẽ được hiển thị trong trò chơi ) và các ô trong bảng sẽ có một hàm để kiểm tra xem người chơi có đang thực hiện hay đã thực hiện tương tác bằng chuột hay chưa.
  -	Cụ thể hơn, nếu người chơi tương tác với trò chơi qua chuột (di chuyển, nhấp chuột, nhả chuột).
  -	Dùng hàm SDL_GetMouseState để xác định tọa độ theo chiều ngang và dọc của con trỏ chuột, sử dụng công thức để tính được con trỏ chuột đang chỉ vào ô nào trong bảng, dựa vào việc tính tọa độ theo chiều ngang và dọc của ô . 
  -	Kiểm tra vị trí tương đối của chuột với các ô trong bảng (vị trí của chuột nằm bên trái, phải hay trên, dưới của ô đều được xét là trường hợp nằm ở ngoài ô). Nếu vị trí chuột trỏ tới là trong ô, xét đến thao tác chuột của người chơi, trước tiên là nếu người chơi chọn nhấn chuột vào ô đang chỉ tới thì sẽ cho phát hiệu ứng âm thanh thể hiện người chơi đã click được vào ô. Tiếp đó, xét đến thao tác chính xác người chơi thực hiện với chuột, cụ thể là nhấp chuột trái hoặc chuột phải. Nếu người chơi nhấp chuột trái (thao tác để mở ô), chạy hàm reveal với đối số truyền vào là tọa độ của ô được chọn (hàm sẽ tiết lộ ô đó nếu nó không chưa mìn và các ô xung quanh nó mà có chỉ số là 0 hay không có mìn xung quanh) nếu ô đó chứa mìn thì trò chơi kết thúc và người chơi thua cuộc. Nếu người chơi nhấp chuột phải (thao tác để đặt cờ cho ô), nếu giá trị của ô trong mảng sBoard là 10 (tức là ô chưa được mở), nếu biến đếm số mìn còn lại là 0 (tức là số cờ đã được đặt bằng tổng số mìn đang có trên bảng) thì sẽ không thực hiện thao tác đặt cờ, nếu biến đếm số mìn còn lại khác không, ta sẽ đặt giá trị của ô được chọn trên mảng sBoard là 11 (biểu thị cho việc ô được đặt cờ) và giảm số mìn còn lại đi một. Nếu người chơi thao tác đặt cờ trên một ô đã có cờ, trò chơi sẽ hiểu rằng người chơi muốn gỡ lá cờ đó đi, khi này, đặt lại giá trị của ô được chọn trên mảng sBoard là 10 và tăng biến đếm số mìn lại lên 1.

  -	Ở trên ta có đề cập đến hàm reveal, chức năng của hàm này là tiết lộ (reveal) ô đã được chọn và các ô an toàn xung quanh nó (các ô có chỉ số là 0 hay không có mìn xung quanh).
  -	Nếu giá trị của ô có tọa độ là đối số truyền vào có giá trị khác 10 hoặc 11 thì hàm sẽ không có ảnh hưởng gì đến trò chơi.
  -	Nếu giá trị của ô được chọn có giá trị là 11 (hay là một ô đang được đặt cờ) thì giữ nguyên giá trị đó và thực hiện tăng biến đếm số mìn còn lại lên 1 
  -	Gán giá trị các ô trong bảng board (bảng chìm) cho bảng sBoard (bảng hiển thị) và giảm biến đếm số ô chưa được mở đi một.
  -	Sau khi gán, lúc này, nếu giá trị của ô đang chọn là 0, tức là xung quanh nó không có ô nào chứa mìn, thì t tiếp tục gọi hàm reveal cho 8 ô xung quanh nó. Về cơ bản, nếu ô được chọn có giá trị trong khoảng từ 1 đến 8 thì ta sẽ chỉ reveal ô đó còn nếu ô đó có giá trị là 0 thì ta sẽ tiếp tục mở những ô xung quanh đó cho đến khi gặp một ô có giá trị trong khoảng tư 1 đến 8. 

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

3.	Mô tả các chức năng đã cài đặt, kèm video minh họa ( chèn link video youtube ):
-	Trò chơi được cài đặt những tính năng cơ bản của dò mìn cổ điển.
-	Cho phép người chơi đặt cờ và ô đã được đặt cờ sẽ không thể mở được để tránh việc vô ý bấm nhầm, hiển thị biểu tượng sẽ có biểu cảm thay đổi mỗi khi người chơi thực hiện tương tác, chiến thắng hay thua cuộc, biểu tượng trên cũng có thể được nhấp trái vào để thực hiện chơi lại từ đầu, thực hiện phát các hiệu ứng âm thanh tương ứng khi người chơi tương tác chuột ở với Menu, biểu tượng hay các ô trong bảng và khi trò chơi kết thúc.
-	Cài đặt được Menu hiển thị mỗi khi khởi động trò chơi với ba lựa chọn mức độ khó khác nhau và hai lựa chọn Theme cho trò chơi trước khi bắt đầu.
-	Link Video Youtube: https://www.youtube.com/watch?v=xA4YyMH3yOM

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

4.	Các kỹ thuật lập trình được sử dụng 
-	Sử dụng mảng kiểu biến int như đã đề cập để lưu dữ liệu sử dụng cho trò chơi, bên cạnh đó là mảng dữ liệu kiểu SDL_Rect và LTexture để hỗ trợ render hình ảnh lên cửa sổ trò chơi và mảng kiểu LButton là lớp dữ liệu sẽ chứa hàm xử lí trực tiếp thao tác chuột của người chơi.
-	Ứng dụng con trỏ cho các kiểu biến thông dụng như:
-	SDL_Window: struct giữ tất cả các thông tin của cửa sổ được tạo ra, chẳng hạn như size, postion, border, fullscreen.
-	SDL_Renderer: struct xử lý tất cả các công việc rendering lên cửa sổ.
-	SDL_Surface: chứa 1 tập hợp các pixel (a collection of pixels) để có thể render lên cửa sổ sử dụng software rendering (CPU).
-	SDL_Texture: chứa 1 tập hợp các pixel (a collection of pixels) để có thể render lên cửa sổ sử dụng hardware rendering (GPU).
-	TTF_Font: giúp quản lý các thông tin liên quan đến font chữ để có thể vẽ lên màn hình.
-	Sử dụng hai lớp lớn đó là LTexture và LButton với các hàm thành viên:
-	Lớp LTexture:
-	LTexture và ~LTexture lần lượt để khởi tạo và giải phóng bộ nhớ.
-	loadFromRenderedText thực hiện tạo ra Texture ảnh từ string nhận vào là nội dung của chuỗi muốn hiển thị, SDL_Color nhận vào là màu sử dụng cho Texture và font chữ được sử dụng toàn cục.
-	loadFromFile thực hiện load ảnh từ đường dẫn hay địa chỉ truyền vào dưới dạng string.
-	free thực hiện giải phóng Texture.
-	Các hàm setColor, setBlendMode, setAlpha và render để hỗ trợ render hình ảnh lên cửa sổ.
-	Hai hàm getWidth và getHeight để lưu dữ liệu về kích thước ảnh. 
-	Lớp LButton: 
-	LButton để khởi tạo.
-	setPosition để gán vị trí tọa độ cho các nút.
-	Các hàm handleEvent, emoteHandleEvent, menuHandleEvent để xử lí thao tác của người chơi với trò chơi ( với các ô, biểu tượng và lựa chọn Menu ).
-	Các hàm tileRender, emoteRender và menuRender như tên gọi để render hình ảnh của các ô, biểu tượng và Menu lên cửa sổ.
-	Cài đặt và sử dụng thư viện đồ họa SDL ( SDL_image, SDL_mixer, SDL_tft ) để hỗ trợ tải lên file hình ảnh, âm thanh và font chữ cho trò chơi.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

5.	Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình
-	Kết luận: Khi bắt đầu làm dự án, em vẫn còn khá mơ hồ về tư duy để lập trình một trò chơi, em chọn làm dò mìn phần nhiều là vì đó là trò chơi mà em nghĩ đến đầu tiên do có nhiều thời gian chơi lúc nhỏ, lựa chọn đó trong suốt quá trình em làm dự án sau này có cả những điểm tốt và không tốt. Sau khi chọn được trò chơi mình đã làm, em bắt đầu cài đặt thư viện SDL và mất khá lâu để thực hiện được nhưng sau khi hiểu rõ cách làm thì việc cài thêm SDL_image, SDL_mixer hay SDL_tft sau này trở nên dễ dàng hơn nhiều. Tiếp đó em bắt đầu tự học các về SDL trên qua các tutorials trên mạng nhưng đến một lúc nhất định em đã quyết định bắt tay vào làm rồi làm đến đâu thì học đến đó. Em có tìm được trên mạng rất nhiều hướng dẫn về trò chơi mà mình đang thực hiện và em đã chọn một cái để làm theo. Lúc đầu thì em chỉ làm theo y hệt đơn giản là vì em vẫn còn khó khăn trong việc đọc và hiểu các hàm cũng như cách xây dựng và quản lí các phần khác nhau để cấu thành một trò chơi hoàn chỉnh. Khi đã tìm hiểu hết bề nổi, công việc của các hàm chức năng hỗ trợ em chuyển sang tìm hiểu thuật toán chính của trò chơi, đến phần này lúc đầu đọc em thấy hơi trừu tượng nên em đã thử bắt đầu với phiên bản không có đồ họa của dò mìn và dần dần hiểu rõ được những thuật toán của trò chơi. Sau khi hoàn thành bước cơ sở, em mới bắt đầu thêm vào các tính năng mới như menu độ khó, chỉnh sửa một số hàm xử lí thao tác cũ và tổ chức lại các hàm khác đi. 
-	Như đã trình bày trong video em có vài ý tưởng phát triển cho trò chơi, đầu tiên là việc nếu đặt cờ đúng thì việc nhấn thêm một lần nữa vào ô đã mở sẽ tiết lộ hết các ô an toàn xung quanh nó, còn nếu đặt cờ sai thì tính thua cho người chơi. Thứ hai là do thuật toán mà em tìm được cũng như đang sử dụng sẽ cho sinh mìn hoàn toàn ngẫu nhiên nên sẽ có rất nhiều trường hợp người chơi sẽ không có một chút dữ liệu nào để xác định ô chứa mìn mà chỉ có thể phán đoán nên em định thêm vào tính năng cho phép người chơi có một số lượt bấm vào mìn nhất định mà vẫn được tiếp tục trò chơi nhưng em gặp vấn đề logic và xử lí tọa độ các ô khi đang thử thực hiện tính năng thứ nhất và chưa có ý tưởng rõ ràng cho ý tưởng thứ hai nên chưa hiện thực hóa được. 
-	Qua dự án, em đã phần nào học được cách cải thiện khả năng tự tìm tòi kiến thức và thông tin cũng như tiếp cận với thư viện SDL, với cách tư duy về mặt hình ảnh dù chưa hiểu được bản chất của một số hàm kể cả cơ bản trong thư viện nhưng em cũng đã nắm bắt được chức năng và ứng dụng của chúng trong các hoàn cảnh khác nhau.

