class Infix :
    data = 0
    prefix = 0
    postfix = 0
    def __init__(self ,data):
        self.data = data
    def prefix(self):
        temp = self.data
        return temp
    def postfix(self):
        stack = []
        postfix = []
        for c in self.data:
            if c in OPERATORS:

                if stack:
                    top = stack[-1]

                    while top in OPERATORS and OPERATORS[top] >= OPERATORS[c]:
                        postfix.append(stack.pop())

                        if stack:
                            top = stack[-1]
                        else:
                            break

                stack.append(c)

            elif c in PARENTHESIS:

                if c == ")":
                    if len(stack) > 0:
                        top = stack[-1]

                        while top != "(":
                            try:
                                # pop throws an IndexError if the list is empty
                                r = stack.pop()
                                postfix.append(r)  # Adding what's in between ( ) to the postfix list
                                top = stack[-1]
                            except IndexError:
                                raise ValueError("'(' not found when popping")

                        stack.pop()  # Removes ( from the top of the stack
                    else:
                        raise ValueError("')' cannot be added to the stack if it is empty") 
                else:
                    stack.append(c)  # c == '('
            else:

                postfix.append(c)

            #print("Stack:", stack)
            #print("Postfix:", postfix)

        while len(stack) > 0:
            top = stack.pop()

            if top in OPERATORS.keys():
                postfix.append(top)

        return postfix

while 1:
    infix = Infix(input('Infix ra vared konid : '))
    print(infix.postfix())