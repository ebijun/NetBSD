#! /usr/pkg/bin/ruby31

require 'open-uri'
require 'nokogiri'

url = 'https://togetter.com/id/ebijun?page='+ARGV[0]

charset = nil

html = URI.open(url) do |f|
  charset = f.charset
  f.read
end

doc = Nokogiri::HTML.parse(html, nil, charset)

doc.xpath("//div[@class='inner']").each do |item|
	c     = item.css('span').children

	if (c.size == 0 || c.size == 4)
		next
	end

	# bypass Blank paragraph, text size = 4
	if c[0].inner_text.size == 4
		next
	end
	title = item.css('h3').inner_text
	url = item.css('a').attribute('href').value

	puts title+','+url+","+c[6].children.children.inner_text
end
