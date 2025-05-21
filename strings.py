class string:
  def __init__(self, word):
    self.word = word

  def toUpperCase(self):
    word = self.word
    '''
      ASCII:
        a = 97
        z = 123
        A = 65
        Z = 90
        |a - A| = 32
        |lower_case - upper_case| = 32
        upper_case = lower_case - 32
        lower_case = upper_case + 32
    '''
    new_string = str()
    for ch in word:
      ascii = ord(ch)
      if ascii >= 65 and ascii <= 90:
        new_string += ch
      elif ascii >= 97 and ascii <= 123:
        new_string += chr(ascii - 32)
      else:
        new_string += ch
    return new_string
      
  def toLowerCase(self):
    word = self.word
    '''
      ASCII:
        a = 97
        z = 123
        A = 65
        Z = 90
        |a - A| = 32
        |lower_case - upper_case| = 32
        upper_case = lower_case - 32
        lower_case = upper_case + 32
    '''
    new_string = str()
    for ch in word:
      ascii = ord(ch)
      if ascii >= 97 and ascii <= 123:
        new_string += ch
      elif ascii >= 65 and ascii <= 90:
        new_string += chr(ascii + 32)
      else:
        new_string += ch
    return new_string

  def isNumeric(self):
    word = self.word
    '''
      If a string is numeric then every value has to be in-between 48 - 57
      0: 48
      9: 57
    '''
    for ch in word:
      ascii = ord(ch)
      if ascii < 48 or ascii > 57:
        return False
    return True 

  def join(collection, _join_):
    new_string = ''
    for word in collection:
      new_string += word + _join_
    return new_string
    
  def capitalize(self):
    word = self.word
    words = word.split()
    collection = []
    for w in words:
      collection.append(self.toUpperCase(w[0]) + w[1:])
    return self.join(collection, ' ')

  def title(self):
    word = self.word
    words = word.split()
    new_words = []
    for w in words:
      new_words.append(self.capitalize(w))
    return ' '.join(new_words)

  def isEmail(self):
    word = self.word
    '''
      email: alice@gmail.com
      name: alice
      domain: gmail
      sub-dom: com
      Acceptance:
      NAME: {alpha} > 1
      DOMAINS: [gmail, apple, outlook, hotmail, yahoo]
      SUB: com
    '''
    if (
        word.find('@') != -1 and 
        word.find('.') != -1 and 
        word[0: word.find('@')].isalpha() and
        word[word.find('@') + 1: word.find('.')] in
        ['gmail', 'apple', 'outlook', 'hotmail', 'yahoo'] and
        word[word.find('.') + 1: len(word)] == 'com'
      ):
      return True
    return False

email = string("test@gmail.com")
print(email.isEmail())
print(email.toUpperCase())
