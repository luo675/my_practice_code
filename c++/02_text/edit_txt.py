from pathlib import Path


BASE_DIR=Path(__file__).parent.resolve()

txt_files=list(BASE_DIR.glob("*.txt"))
print(txt_files)

user_input = input("请输入一个文件名")

file_path=BASE_DIR/user_input

text=file_path.read_text(encoding="utf-8")

print(f"文件一共有{len(text)}个字")

delete_text=input("请输入要删除的内容：")

new_text=text.replace(delete_text,"")

file_path.write_text(new_text,encoding="utf-8")

print("删除完成")