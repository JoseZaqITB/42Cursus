# CURSUS 42
## INIT
you will have to copy this function into your zsh to save time in copying files into your 42project.
```
cp42local() {
	find . -type d -name "task-98Y2" -exec cp -r {}/. "$1" \;
}

cp42remote() {
	find . -type d -exec cp -r {}/. "$1" \;
}

mkdir42() {
        mkdir -p "$1"/task-98Y2
        cd "$1"/task-98Y2
}

```
## VSCODE
Usefull extensions:
- 42 Header
- norminette-42

vscode settings ( norminette rules ):
```JSON
{
	"editor.tabSize": 4,
	"editor.insertSpaces": false,
	"editor.renderWhitespace": "all",
	"files.trimTrailingWhitespace": true,
	"files.insertFinalNewline": true,
}
```
