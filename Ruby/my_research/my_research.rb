require 'open-uri'
require 'nokogiri'
require 'csv'
require_relative 'search.rb'

url = 'https://www.ebay.com'
file = "file1.csv"

parser_object = Search.new
parser_object.get_data_write_to_csv(url, file)