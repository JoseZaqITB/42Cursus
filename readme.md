# CURSUS 42
## INIT
you will have to copy this function into your zsh to save time in copying files into your 42project.
```
cp42() {
	find . -type d -name "task-98Y2" -exec cp -r {}/. "$1" \;
}

```
