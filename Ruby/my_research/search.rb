class Search
    attr_accessor :content
    def initialize
      @content=""
    end
    def get_data_write_to_csv(url, file_name)
      html = open(url) { |result| result.read }
      @content = Nokogiri::HTML(html)
      CSV.open(file_name, "w+") do |csv|
        csv << ["Ціна"]
        @content.css("li.carousel__snap-point hl-carousel__item hl-standard-carousel__item").each do  |item|
          begin
            title = get_title(item)
            price = get_price(item)
            csv << [title, price]
          rescue
          end
        end
      end
    end
    def get_price(item)
      item.css("span.hl-item__displayPrice").text.strip
    end
    def get_title(item)
     item.css("span.goods-tile__price-value").text.strip
    end
  end