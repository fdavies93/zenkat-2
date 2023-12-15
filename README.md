# ZenKat 2

## Parsing

AST parsing is handled by forking
[cmark-gfm](https://github.com/github/cmark-gfm/tree/master) and adding
additional code to recognise several extensions not part of github flavored
markdown.

### YAML Headers

These provide metadata about the document.

```
---
title: An Example Title
date: 2023-12-01
tags: beta, fish, lamp
---
```

### Advanced task lists

Any character is now allowed in task boxes and can represent alternative states of
the task.

```
- [ ] Standard incomplete
- [x] Standard complete
- [/] In progress
- [-] Blocked
```

### Wiki-style links

```
[[Other article]]
```

### Tags and nested tags

Tags will be auto-expanded where the first level represents the top level of a
tag, and the / character represents.

```
#journal #2023/11/23

Equivalent to:

#journal #2023 #2023/11 #2023/11/23
```
