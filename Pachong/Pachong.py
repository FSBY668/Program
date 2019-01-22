#!/usr/bin/env python
# encoding=utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import requests as r
from bs4 import BeautifulSoup as bs
import csv
import re
import codecs
from multiprocessing.dummy import Pool

movies = []
url = ['https://movie.douban.com/top250?start={}'.format(str(i)) for i in range(0,226,25)]

def soup(url):
    html = r.get(url).text
    items = bs(html, "lxml").find_all('div','item')
    for item in items:
        movie_name = item.find('span','title').string
        movie_rating = item.find('span','rating_num').string
        try:
            movie_quote = item.find('span','inq').string
        except:
            movie_quote='none'
        movie_info = item.find('div','bd').find('p','').get_text()
        if len(re.findall('\d{4}',movie_info)) == 0:
            movie_year = 'none'
        else:
            movie_year = re.findall('\d{4}',movie_info)[0]
        if len(re.findall('(?<=\d./).*(?=/)',movie_info)) == 0:
            movie_nation = 'none'
        else:
            movie_nation = re.findall('(?<=\d./).*(?=/)',movie_info)[0]
        movie = (movie_name,movie_year,movie_rating,movie_nation,movie_quote)
        movies.append(movie)

pool = Pool()
pool.map(soup, url)
pool.close()
pool.join()

with codecs.open('DoubanMovieTOP250.csv','w','utf-8') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(["Film name","Year","Note","Region","Introduction"])
    writer.writerows(movies)
