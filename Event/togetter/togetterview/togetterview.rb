#! /usr/pkg/bin/ruby27

require 'open-uri'
require 'nokogiri'

url = 'https://togetter.com/id/ebijun?page='+ARGV[0]

charset = nil

html = open(url) do |f|
  charset = f.charset
  f.read
end

doc = Nokogiri::HTML.parse(html, nil, charset)

doc.xpath("//div[@class='inner']").each do |item|
	title = item.css('h3').inner_text
	url   = item.css('a').attribute('href').value

	c     = item.css('span').children

	if c.size == 0
		next
	end
	if c[0].inner_text.size == 0
		next
	end
	puts title+","+url+","+c[0].inner_text
end
