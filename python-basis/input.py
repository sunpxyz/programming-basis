# input.py
# 2.1.2017


import string


def reverse(text):
    return text[::-1]


def is_palindrome(text):
    text = text.lower()
    text = text.replace(' ', '')
    for char in string.punctuation:
        text = text.replace(char, '')
    return text == reverse(text)


def main():
    something = input('Enter text:')
    if is_palindrome(something):
        print('Yes, "{0}" is a palindrome.'.format(something))
    else:
        print('Yes, "{0}" is not a palindrome.'.format(something))

if __name__ == '__main__':
    main()
else:
    print('input.py was imported!')
