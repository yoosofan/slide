
# Extract names of students who are present in class from lms kashanu

import csv, re, os, datetime

def strip_csv(fname, fname2):
  with open(fname) as csv1, open(fname2, 'w') as csv2:
    reader = csv.reader(csv1)
    writer = csv.writer(csv2)
    l2 = []
    for m1 in reader:
      l2.append([m1[0].strip(), m1[1].strip(), m1[2].strip()])
    writer.writerows(l2)

def list_of_names(name2):
  outtxt = 'input/' + name2 + '_out.txt'
  nametxt = 'input/' + name2 + '.txt'
  with open(nametxt, encoding='utf-8') as f1:
    l1 = [x.strip() for x in f1.readlines()];
  l2 = []
  for m1 in l1:
    a = re.match('\[([0-9]){2}:([0-9]){2}\] ', m1)
    if a is not None:
      k1 = m1[a.end():].split(':')
      if len(k1) > 1 :
        k2 = k1[0].strip()
        if len(k2) < 40:
          if k2 not in l2:
            l2.append(k2)

  # ~ l2.sort()
  # ~ import PyICU
  # ~ collator = PyICU.Collator.createInstance(PyICU.Locale('fa_IR.UTF-8'))
  # ~ print ([i for i in sorted(['ا', 'ب', 'پ', 'ح', 'س', 'ص', 'ف', 'ک', 'ک', 'ک', 'م', 'م'], key=collator.getSortKey)])
  # ~ https://stackoverflow.com/a/54458977/886607

  with open(outtxt, 'w', encoding='utf-8') as f2:
    for m1 in l2:
      f2.write(m1+'\n')
  # ~ namecsv = 'input/' + name2 + '2.csv'
  # ~ with open(namecsv) as csvfile, open(nametxt, encoding='utf-8') as f1:
  # ~ from difflib import SequenceMatcher
  # ~ s = SequenceMatcher(None, "abcd", "bcde")
  # ~ s.ratio()
  # ~ https://stackoverflow.com/a/46125447/886607
  # ~ https://www.datacamp.com/community/tutorials/fuzzy-string-python
  # ~ https://en.wikipedia.org/wiki/Hamming_distance
  # ~ https://en.wikipedia.org/wiki/Levenshtein_distance
  # ~ https://en.wikipedia.org/wiki/Damerau%E2%80%93Levenshtein_distance
  # ~ https://en.wikipedia.org/wiki/Jaro%E2%80%93Winkler_distance
  # ~ https://betterprogramming.pub/fuzzy-string-matching-with-python-cafeff0d29fe
  # ~ https://towardsdatascience.com/calculating-string-similarity-in-python-276e18a7d33a

def f1(name2, time2):
  namecsv = 'input/' + name2 + '.csv'
  nametxt = 'input/' + name2 + '.txt'
  outtxt = 'output/' + name2 + '_out.txt'
  with open(nametxt, encoding='utf-8') as f1:
    l1 = [x.strip() for x in f1.readlines()];
  print(l1[-1])
  l2 = []
  p = re.compile('\[\d{2}:\d{2}\] ')
  for m1 in l1:
    a = p.match(m1)
    if a is not None:
      # ~ print(a.group())
      k1 = m1[a.end():].split(':')
      if len(k1) > 1 and len(k1[0]) < 40:
        if m1[a.start()+1:a.end()-2] >= time2:
          k2 = k1[0].strip()
          if k2 not in l2:
            l2.append(k2)

  # ~ print(l2)
  # ~ with open(outtxt, 'w', encoding='utf-8') as f2:
    # ~ for m1 in l2:
      # ~ f2.write(m1+'\n')
  # ~ return outtxt

  with  open(namecsv) as csvfile:
    reader = csv.DictReader(csvfile)
    l3 = []
    for row in reader:
      m4 = row['lmsname'].strip() 
      if m4 in l2:
        l3.append('10')
      else:
        l3.append('0')
  with open(outtxt, 'w', encoding='utf-8') as f2:
    for m1 in l3:
      f2.write(m1+'\n')

  with open('outtxt11.txt', 'w', encoding='utf-8') as f2:
    for m1 in l2:
      f2.write(m1+'\n')

  return outtxt

def prepare_csvs():
  list_of_names('cpp')
  # ~ strip_csv('input/cpp.csv', 'input/cpp.csv')

def detect_session():
  today1 = datetime.datetime.today()
  d1 = today1.weekday()
  t1 = today1.strftime('%H%M')
  print(t1)
  print(d1)
  course_name = 'no'
  start_time = '0000'
  if d1 == 5 or d1 == 0: # d1 == 0 ==> Monday, d1 == 5 ==> Saturday
    if '0955' <= t1 <= '1245':
      course_name = 'mp'
      start_time = '1001'
      if '1220' <= t1 <= '1245':
        start_time = '1220'
    elif '1359' <= t1 <= '1535':
      print('sss');
      course_name = 'cpp'
      start_time = '1401'
      if '1520' <= t1 <= '1535':
        start_time = '1515'
  return [course_name, start_time]

if __name__ == '__main__':
  # ~ prepare_csvs()  # ~ exit();
  m1 = detect_session()
  # ~ m1 = ['mp', '1516']
  if m1[0] != 'no':
    m2 = f1(m1[0], m1[1])
    os.system('geany '+ m2)
  else:
    print('not in time of class')


