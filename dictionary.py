class collection:
  def pair(self, k, v):
    self.key = k
    self.value = v
    return self
  
class dictionary:
  memory = []
  def __init__(self, threshold):
    self.memory = [False for i in range(threshold)]
    self.threshold = threshold

  def position(self, key):
    idx = 0
    for ch in key:
      idx += ord(ch)
    idx = idx % self.threshold
    return idx
  
  def save(self, key, value):
    address = collection().pair(key, value)
    pos = self.position(key)
    if self.memory[pos] == False:
      self.memory[pos] = address   
    else:
      values = self.memory[pos]
      self.memory[pos] = []
      self.memory[pos].append(values)
      self.memory[pos].append(collection().pair(key, value))
      
    
  def items(self):
    items_list = []
    for obj in self.memory:
      if obj  != False and type(obj) != list:
        items_list.append((obj.key, obj.value))
      elif obj  != False and type(obj) == list:
        for o in obj:
          items_list.append((o.key, o.value))
    return items_list
  
  def get(self, key):
    pos = self.position(key)
    if self.memory[pos] != False and type(self.memory[pos]) != list:
      return self.memory[self.position(key)].value
    elif self.memory[pos] != False and type(self.memory[pos]) == list:
      for i in self.memory[pos]:
        if i.key == key:
          return i.value
    return -1
  
  
  
'''
 0 1 2 3 4 
|e| | | | |

Simulation of dictionary data-structure mechanism, this can be even optimized by using tree's in the case of collision.
I have designed the optimized version using C language for my GARUDA programming language, which internally uses binary trees instead of linked lists.
'''
