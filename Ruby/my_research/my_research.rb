require 'open-uri'
require 'nokogiri'
require 'csv'
require_relative 'search.rb'

url = 'https://rozetka.com.ua/mobile-phones/c80003/'
file = "file.csv"

parser_object = Search.new
parser_object.get_data_write_to_csv(url, file)